#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <esp_dmx.h>

#include "Html_code.h"
#include "favicon_bin.h"

using namespace std;

const char *ssid = "DMX-Remote";
const char *password = "Optik_101";

int transmitPin = 17;
int receivePin = 18;
int enablePin = 4;
dmx_port_t dmxPort = 1;


IPAddress local_IP(192, 168, 1, 1);  // Static IP address for AP mode
IPAddress gateway(192, 168, 1, 1);   // Gateway address
IPAddress subnet(255, 255, 255, 0);  // Subnet mask

WebServer server(80);
Adafruit_NeoPixel strip(1, 48, NEO_GRB + NEO_KHZ800);

// Initialize channel values
int currentValues[12];
int presetList[10][12]; 

void setup() {
  pinMode(5, OUTPUT);
  pinMode(48, OUTPUT);
  digitalWrite(5, HIGH);

  EEPROM.begin(10*12 + 1);
  Serial.begin(115200);

  //Setup DMX Tx
  dmx_config_t config = DMX_CONFIG_DEFAULT;
  dmx_personality_t personalities[] = {};
  int personality_count = 0;
  dmx_driver_install(dmxPort, &config, personalities, personality_count);
  dmx_set_pin(dmxPort, transmitPin, receivePin, enablePin);

  // Set up ESP32 in Access Point (AP) mode with static IP
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);

  // Get IP address of the AP
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  //Serve Webpage
  server.on("/", serveWebPage);
  server.on("/favicon.ico", favicon);
  server.on("/set_channel", setChannel);
  server.on("/set_preset", setPreset);
  server.on("/get_preset", getPreset);

  server.begin();
  Serial.println("HTTP server started");
  strip.begin();
  strip.setPixelColor(0,0,10,0);
  strip.show();
}

void loop() {
  server.handleClient();
}

int* splitStringToIntArray(String input) {
  // Remove '[' and ']' from the string
  input.remove(0, 1);
  input.remove(input.length() - 1, 1);
  int   ArrayLength  = input.length()+1;    //The +1 is for the 0x00h Terminator
  char  CharArray[ArrayLength];
  input.toCharArray(CharArray,ArrayLength);
  char* tok = strtok(CharArray, ",");
  static int output[12];
  for (int i = 0; i < 12; i++) {
    output[i] = atoi(tok);
    tok = strtok(NULL, ",");
  }
  return output;
}

void storePreset() {
  for (int nPreset = 0; nPreset < 10; nPreset++) {
    for (int nChannel = 0; nChannel < 12; nChannel++) {
      int address = nPreset*12 + nChannel+1;
      EEPROM.write(address, presetList[nPreset][nChannel]);
    }
  }
  EEPROM.commit();
}

void loadPreset() {
  for (int nPreset = 0; nPreset < 10; nPreset++) {
    for (int nChannel = 0; nChannel < 12; nChannel++) {
      int address = nPreset*12 + nChannel+1;
      presetList[nPreset][nChannel] = EEPROM.read(address);
    }
  }
}

void sendDMX() {
  byte DMXchannel[DMX_PACKET_SIZE];
  DMXchannel[1] = currentValues[0];
  DMXchannel[2] = currentValues[1];
  DMXchannel[3] = currentValues[2];
  DMXchannel[4] = currentValues[3];
  DMXchannel[5] = 0;
  DMXchannel[6] = 0;
  DMXchannel[7] = 0;
  DMXchannel[8] = currentValues[4];
  DMXchannel[9] = currentValues[5];
  DMXchannel[10] = currentValues[6];
  DMXchannel[11] = currentValues[7];
  DMXchannel[12] = 0;
  DMXchannel[13] = 0;
  DMXchannel[14] = 0;
  DMXchannel[15] = currentValues[8];
  DMXchannel[16] = currentValues[9];
  DMXchannel[17] = currentValues[10];
  DMXchannel[18] = currentValues[11];
  DMXchannel[19] = 0;
  DMXchannel[20] = 0;
  DMXchannel[21] = 0;
  dmx_wait_sent(dmxPort, DMX_TIMEOUT_TICK);
  dmx_write(dmxPort, DMXchannel, DMX_PACKET_SIZE);
  dmx_send_num(dmxPort, DMX_PACKET_SIZE);
}

void serveWebPage() {
  // server.sendHeader("Content-Encoding", "gzip");
  server.send(200, "text/html", Html_code);
}

void favicon() {
  server.send_P(200, "image/x-icon", PAGE_favicon, sizeof(PAGE_favicon));
}

void setChannel() {
  String channelStr = server.arg("channel");
  String valueStr = server.arg("value");
  if (channelStr == "" || valueStr == "")                         { server.send(400, "text/plain", "Error: EmptyError"); return; } //Empty req
  int channel = channelStr.toInt();
  int value = valueStr.toInt();
  if (channel < 1 || channel > 12 || value < 0 || value > 255)    { server.send(400, "text/plain", "Error: OutOfRange"); return; } //Out of Range
  if (value < 5) { value=0; }                                                     //If value to little, turn off lamp to aknolege for 1% problem
  currentValues[channel - 1] = value;
  sendDMX();
  server.send(200, "text/plain", "Ok");
  return;
}

void getPreset() {
  // Get channel number and value from the request
  String presetIdStr = server.arg("presetId");
  if (presetIdStr == "")                         { server.send(400, "text/plain", "Error: EmptyError"); return; } //Empty request
  int presetId = presetIdStr.toInt();
  if (presetId < 1 || presetId > 10)    { server.send(400, "text/plain", "Error: presetId OutOfRange"); return; } //Out of Range
  loadPreset();
  String response;
  response = "[";
  for (int i = 0; i < 12; i++)
  {
    response = response + String(presetList[presetId - 1][i]) + ",";
  }
  response.remove(response.length()-1);
  response = response + "]";
  server.send(200, "text/plain", response);
  return;
}

void setPreset() {
  String presetIdStr = server.arg("presetId");
  String PresetvaluesStr = server.arg("values");
  if (presetIdStr == "" || PresetvaluesStr == "")                         { server.send(400, "text/plain", "Error: EmptyError"); return; } //Empty request
  int presetId = presetIdStr.toInt();
  if (presetId < 1 || presetId > 10)    { server.send(400, "text/plain", "Error: presetId OutOfRange"); return; } //Out of Range
  if (PresetvaluesStr.length() < 25)      { server.send(400, "text/plain", "Error: NortEnoughValues"); return; }
  int* presetValues;
  presetValues = splitStringToIntArray(PresetvaluesStr);
  for (int i = 0; i < 12 ; i++) {
    if (presetValues[i] < 0 || presetValues[i] > 255) { server.send(400, "text/plain", "Error: presetValues OutOfRange"); Serial.println(String(presetValues[i]) + ": index " + String(i) + " Is greater than 255 of tynier than 0"); return; } //Out of Range
  }
  for (int i = 0; i < 12 ;i++) {
    presetList[presetId - 1][i] = presetValues[i];   //Write the current preset in the list
  }
  storePreset();
  sendDMX();
  server.send(200, "text/plain", "Ok");

  return;
}