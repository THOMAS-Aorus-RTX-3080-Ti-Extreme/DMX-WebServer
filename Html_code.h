#ifndef HTML_CODE_H
#define HTML_CODE_H

const char Html_code[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0", http-equiv="refresh" content="3">
    <title>DMX Remote</title>
    <style>

        body {
            background: #fff;
            margin: 30px auto;
            text-align: center;
            font-family: helvetica;
        }
        header_title {
            color: #c00000;
            font-size: 50px;
            font-style: italic;
            font-weight: 800;
            letter-spacing: 2px;
        }

        .scene_section {

width: 50%;
        }
        .scene_wrapper {
        display: block;
        background-color: #ffffff;
        border: 1px solid #000;
        border-radius: 10px;
        box-shadow: 5px 5px 10px rgba(0, 0, 0, 0.3);
        width: 280px;
        display: flex;
        flex-direction: column;
        margin-top: 20px;
        margin-left: 60px;
        padding-top: 10px;
        font-size: 22px;
        font-weight: 500;
        }
        .scene_inner_wrapper {
        width: 100%;
        display: flex;
        flex-direction: row;
        }
        .scene_large_button {
        /*background: linear-gradient(to right,#ccc 0%, #ccc 33.33%, #aaa 33.33%, #aaa 66.66%, #666 66.66%, #666 100%);   --> Now dynamic*/
        background-color: #ccc;
        color: #888;
        border: 1px solid #000;
        cursor: grab;
        display: flex;
        justify-content: center;
        align-items: center;
        width: 150px;
        height: 100px;
        border-radius: 10px;
        font-size: 20px;
        font-weight: 700;
        margin-top: 10px;
        margin-left: 10px;
        }
        .scene_small_button_container {
        margin-bottom: 20px;
        float: left;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        }
        .scene_small_button1 {
        float: left;
        width: 60px;
        height: 40px;
        margin-top: 10px;
        margin-left: 40px;
        
        /*purely visual*/
        background: #3b21e6;
        border-radius: 11px;
        box-sizing: border-box;
        color: #fff;
        cursor: pointer;
        display: flex;
        font-family: Mija,-apple-system,BlinkMacSystemFont,Roboto,"Roboto Slab","Droid Serif","Segoe UI",system-ui,Arial,sans-serif;
        font-size: 15px;
        font-weight: 700;
        justify-content: center;
        text-align: center;
        text-decoration: none;
        text-decoration-skip-ink: auto;
        text-shadow: rgba(0, 0, 0, .3) 1px 1px 1px;
        text-underline-offset: 1px;
        padding-top: 9px;
        }
        .scene_small_button2 {
        float: left;
        width: 60px;
        height: 40px;
        margin-top: 20px;
        margin-left: 40px;
        
        /*purely visual*/
        background: #e62143;
        border-radius: 11px;
        box-sizing: border-box;
        color: #fff;
        cursor: pointer;
        display: flex;
        font-family: Mija,-apple-system,BlinkMacSystemFont,Roboto,"Roboto Slab","Droid Serif","Segoe UI",system-ui,Arial,sans-serif;
        font-size: 15px;
        font-weight: 700;
        justify-content: center;
        text-align: center;
        text-decoration: none;
        text-decoration-skip-ink: auto;
        text-shadow: rgba(0, 0, 0, .3) 1px 1px 1px;
        text-underline-offset: 1px;
        padding-top: 9px;
        }

        .slider_section {
            width: 100%; /* Ensure the container fills the available width */
        }
        .slider_spacer {
            text-align: center;
            margin-top: 50px;
            font-size: 30px;
            font-weight: 700;
        }
        .slider_title {
            margin-bottom: 20px
        }
        .slider_wrapper {
            margin: 10px auto;
            padding: 10px;
            background-color: #fff;
            border: 1px solid #000;
            border-radius: 10px;
            box-shadow: 5px 5px 10px rgba(0, 0, 0, 0.3);
            width: 80%; /* Set the width to 80% or adjust as needed */
        }
        .slider_container{
            display: flex;
            flex-direction: row;
            margin-top: 20px;

        }
        .slider_label {
            white-space: pre;
        }
        .slider_value {
            text-align: left;
            font-size: 30px;
            margin-left: -5px;
            width: 80px; 
        }
        .red_slider {
            background: #f00;
            border: 5px solid #700;
            width: 100%;
            height: 20px;
            border-radius: 20px;
            margin-left: 0px;
            outline: none;
            appearance: none;
        }
        .red_slider::-webkit-slider-thumb {
            background: #911;
            border: 5px solid #700;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
            appearance: none;
        }
        .red_slider::-moz-range-thumb {
            background: #911;
            border: 5px solid #700;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
        }
        .green_slider {
            background: #0f0;
            border: 5px solid #070;
            width: 100%;
            height: 20px;
            border-radius: 20px;
            margin-left: 0px;
            outline: none;
            appearance: none;
        }
        .green_slider::-webkit-slider-thumb {
            background: #191;
            border: 5px solid #070;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
            appearance: none;
        }
        .green_slider::-moz-range-thumb {
            background: #191;
            border: 5px solid #070;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;


        }
        .blue_slider {
            background: #00f;
            border: 5px solid #007;
            width: 100%;
            height: 20px;
            border-radius: 20px;
            margin-left: 0px;
            outline: none;
            appearance: none;
        }
        .blue_slider::-webkit-slider-thumb {
            border: 5px solid #007;
            background: #119;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
            appearance: none;
        }
        .blue_slider::-moz-range-thumb {
            background: #119;
            border: 5px solid #007;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
        }
        .white_slider {
            background: #fff;
            border: 5px solid #aaa;
            width: 100%;
            height: 20px;
            border-radius: 20px;
            margin-left: 0px;
            outline: none;
            appearance: none;
        }
        .white_slider::-webkit-slider-thumb {
            background: #ccc;
            border: 5px solid #aaa;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
            appearance: none;
        }
        .white_slider::-moz-range-thumb {
            background: #ccc;
            border: 5px solid #aaa;
            width: 25px;
            height: 75px;
            border-radius: 8px;
            cursor: pointer;
        }

        footer {
            background: #ffffff;
            color: #000000;
            bottom: 0;
            width: 100%;
            text-align: center;
            font-size: 15px;
            font-style: italic;
            margin-top: 40px;
        }
    </style>
        
</head>

<body>
    <header_title> DMX Remote </header_title>
    <div class="scene_section">
        <!-- Buttons will be dynamically added here -->
    </div>

    <div class="slider_section">
        <!-- Channels and sliders will be dynamically added here -->
    </div>

    <footer>
        <p>Created by Thomas Bringolf, 10c</p>
        <p>Compiled last on 14.04.2024</p>
    </footer>

    <script>
        var presetList = [[]]
        var Channel_items = [0, 2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14, 15];
        var isFetching = false;
        // Returns a String in Percent format
        function convertToPercentage(value) {
            var percentage = Math.round((value / 255) * 100);
            return percentage + '%';
        }     

        // Function to dynamically create scene buttons
        function createSceneButtons(name) {
            var sceneWrapper = document.createElement("div");
                sceneWrapper.classList.add("scene_wrapper");
                sceneWrapper.textContent = name;
                var sceneInnerWrapper = document.createElement("div");
                    sceneInnerWrapper.classList.add("scene_inner_wrapper");
                    var PresetId = name.replace(/\D/g,'');
                    console.log(name);
                    var largeButton = document.createElement("div");
                        largeButton.classList.add("scene_large_button");
                        largeButton.textContent = "Apply";
                        fetch("/get_preset?presetId=" + PresetId)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error('Network response was not ok');
                                }
                                return response.text();
                            })
                            .then(data => {
                                console.log(data);
                                //Response format in String: [0, Dimmer1, R1, G1, B1, 0, 0, 0, Dimmer2, R2, G2, B2, 0, 0, 0, Dimmer3, R3, G3, B3]
                                //convert to array
                                var fetchedPreset = data.replace("[", "").replace("]", "").split(",");
                                presetList[PresetId] = fetchedPreset;
                                console.log(presetList);
                                let dimmedR1 = Math.round(fetchedPreset[1] * (fetchedPreset[0] / 255));
                                let dimmedG1 = Math.round(fetchedPreset[2] * (fetchedPreset[0] / 255));
                                let dimmedB1 = Math.round(fetchedPreset[3] * (fetchedPreset[0] / 255));
                                let dimmedR2 = Math.round(fetchedPreset[5] * (fetchedPreset[4] / 255));
                                let dimmedG2 = Math.round(fetchedPreset[6] * (fetchedPreset[4] / 255));
                                let dimmedB2 = Math.round(fetchedPreset[7] * (fetchedPreset[4] / 255));
                                let dimmedR3 = Math.round(fetchedPreset[9] * (fetchedPreset[8] / 255));
                                let dimmedG3 = Math.round(fetchedPreset[10] * (fetchedPreset[8] / 255));
                                let dimmedB3 = Math.round(fetchedPreset[11] * (fetchedPreset[8] / 255));
                                largeButton.style.background = `linear-gradient(to right, rgb(${dimmedR1}, ${dimmedG1}, ${dimmedB1}) 0%, rgb(${dimmedR1}, ${dimmedG1}, ${dimmedB1}) 33.33%, rgb(${dimmedR2}, ${dimmedG2}, ${dimmedB2}) 33.33%, rgb(${dimmedR2}, ${dimmedG2}, ${dimmedB2}) 66.66%, rgb(${dimmedR3}, ${dimmedG3}, ${dimmedB3}) 66.66%, rgb(${dimmedR3}, ${dimmedG3}, ${dimmedB3}) 100%)`;
                                largeButton.addEventListener("click", function() {setPreset(PresetId)} );
                                return 0;
                            })
                            .catch(error => {
                                console.error('There was a problem with the fetch operation:', error);
                            });

                    sceneInnerWrapper.appendChild(largeButton);
                    var smallButtonContainer = document.createElement("div");
                        smallButtonContainer.classList.add("scene_small_button_container");
                        var smallButton1 = document.createElement("div");
                            smallButton1.classList.add("scene_small_button1");
                            smallButton1.textContent = "Set";
                            smallButton1.addEventListener("click", function() {savePreset(PresetId)} );
                        smallButtonContainer.appendChild(smallButton1);
            
                        var smallButton2 = document.createElement("div");
                            smallButton2.classList.add("scene_small_button2");
                            smallButton2.textContent = "Clear";
                            smallButton2.addEventListener("click", function() {clearPreset(PresetId)} );
                        smallButtonContainer.appendChild(smallButton2);
                    sceneInnerWrapper.appendChild(smallButtonContainer);
                sceneWrapper.appendChild(sceneInnerWrapper);
            document.querySelector(".scene_section").appendChild(sceneWrapper);
        }

        // Function to dynamically create sliders for RGB channels
        function createSlider(channel, color, comment) {
            var wrapper = document.createElement("div");
                wrapper.classList.add("slider_wrapper");
                var sliderContainer = document.createElement("div");
                    sliderContainer.classList.add("slider_container");
                    var sliderValue = document.createElement("div");
                        sliderValue.classList.add("slider_value");
                        sliderValue.textContent = "0%";
                    sliderContainer.appendChild(sliderValue);
                    var slider = document.createElement("input");
                        slider.type = "range";
                        slider.min = "0";
                        slider.max = "255";
                        slider.value = "0";
                        slider.addEventListener("input", function() { throttleUpdateChannel(channel, this.value) }); //Delayed Intemediate update
                        slider.addEventListener("change", function() { delayUpdateChannel(channel, this.value) }); //Imediat update at the end
                        // Add corresponding style class based on the color
                        switch (color) {
                            case "R":
                                slider.classList.add("red_slider");
                                break;
                            case "G":
                                slider.classList.add("green_slider");
                                break;
                            case "B":
                                slider.classList.add("blue_slider");
                                break;
                            case "W":
                                slider.classList.add("white_slider");
                                break;
                            default:
                                break;
                        }
                    sliderContainer.appendChild(slider);
                wrapper.appendChild(sliderContainer);
                var sliderLabel = document.createElement("div");
                    sliderLabel.classList.add("slider_label");
                    sliderLabel.textContent = "           (" + color + ")  ---  [ " + comment + " ]";
                wrapper.appendChild(sliderLabel);
            document.querySelector(".slider_section").appendChild(wrapper);
        }           

        // Function to dynamically create a spacer with a title
        function createSliderSpacer(titleText) {
            var sliderSpacer = document.createElement("div");
                sliderSpacer.classList.add("slider_spacer");
                var title = document.createElement("div");
                    title.classList.add("slider_title");
                    title.textContent = titleText;
                sliderSpacer.appendChild(title);
            document.querySelector(".slider_section").appendChild(sliderSpacer);
        }

        // Function to throttle the updateChannel function
        function throttleUpdateChannel(channel, value) {
            if (!isFetching) {
                isFetching = true;
                updateChannel(channel, value);
            }
        }

        // Function to delay the updateChannel function
        function delayUpdateChannel(channel, value) {
            setTimeout(() => {
                var i = 0;
                do {
                    i++;
                    setTimeout(() => {
                    console.log("WAITING");
                    }, 10);
                } while(isFetching && i < 50);
            
                isFetching = true;
                updateChannel(channel, value);
            }, 100); // Adjust the delay (in milliseconds) as needed
        }

        // Function to update channel value
        function updateChannel(channel, value) {
            var url = "/set_channel?channel=" + channel + "&value=" + value;
            // Send an HTTP GET request to update the channel value
            fetch(url)
                .then(response => {
                    if (!response.ok) {
                        throw new Error('Network response was not ok');
                        isFetching = false;
                    }
                    return response.text();
                })
                .then(data => {
                    console.log(data);
                    isFetching = false; // Reset the flag after the fetch request is completed
                })
                .catch(error => {
                    console.error('There was a problem with the fetch operation:', error);
                    isFetching = false; // Reset the flag in case of an error
                });
            
            // Update the value label with the new value and percentage sign
            console.log(value);
            console.log(channel);
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[channel] + ")").querySelector(".slider_container").querySelector(".slider_value").textContent = convertToPercentage(value); // Check if .container exists
        }

        //Save the Preset values into the ESP32
        function savePreset(presetId, clear = false) {
            //crerate the Preset array with 19 Elements
            if (!clear)
            {
                presetList[presetId][0] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[1] + ")").querySelector(".slider_container").querySelector(".white_slider").value;
                presetList[presetId][1] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[2] + ")").querySelector(".slider_container").querySelector(".red_slider").value;
                presetList[presetId][2] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[3] + ")").querySelector(".slider_container").querySelector(".green_slider").value;
                presetList[presetId][3] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[4] + ")").querySelector(".slider_container").querySelector(".blue_slider").value;
                presetList[presetId][4] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[5] + ")").querySelector(".slider_container").querySelector(".white_slider").value;
                presetList[presetId][5] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[6] + ")").querySelector(".slider_container").querySelector(".red_slider").value;
                presetList[presetId][6] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[7] + ")").querySelector(".slider_container").querySelector(".green_slider").value;
                presetList[presetId][7] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[8] + ")").querySelector(".slider_container").querySelector(".blue_slider").value;
                presetList[presetId][8] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[9] + ")").querySelector(".slider_container").querySelector(".white_slider").value;
                presetList[presetId][9] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[10] + ")").querySelector(".slider_container").querySelector(".red_slider").value;
                presetList[presetId][10] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[11] + ")").querySelector(".slider_container").querySelector(".green_slider").value;
                presetList[presetId][11] = document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[12] + ")").querySelector(".slider_container").querySelector(".blue_slider").value;
            }
            else
            {
                presetList[presetId][0] = 0;
                presetList[presetId][1] = 0;
                presetList[presetId][2] = 0;
                presetList[presetId][3] = 0;
                presetList[presetId][4] = 0;
                presetList[presetId][5] = 0;
                presetList[presetId][6] = 0;
                presetList[presetId][7] = 0;
                presetList[presetId][8] = 0;
                presetList[presetId][9] = 0;
                presetList[presetId][10] = 0;
                presetList[presetId][11] = 0;

            }
            var url = "/set_preset?presetId=" + presetId + "&values=[" + presetList[presetId] + "]";
            fetch(url)
                .then(response => {
                    if (!response.ok) {
                        throw new Error('Network response was not ok');
                    }
                    return response.text();
                })
                .then(data => {
                    console.log(data);
                })
                .catch(error => {
                    console.error('There was a problem with the fetch operation:', error);
                });
            //Update the background of the scene button
            let dimmedR1 = Math.round(presetList[presetId][1] * (presetList[presetId][0] / 255));
            let dimmedG1 = Math.round(presetList[presetId][2] * (presetList[presetId][0] / 255));
            let dimmedB1 = Math.round(presetList[presetId][3] * (presetList[presetId][0] / 255));
            let dimmedR2 = Math.round(presetList[presetId][5] * (presetList[presetId][4] / 255));
            let dimmedG2 = Math.round(presetList[presetId][6] * (presetList[presetId][4] / 255));
            let dimmedB2 = Math.round(presetList[presetId][7] * (presetList[presetId][4] / 255));
            let dimmedR3 = Math.round(presetList[presetId][9] * (presetList[presetId][8] / 255));
            let dimmedG3 = Math.round(presetList[presetId][10] * (presetList[presetId][8] / 255));
            let dimmedB3 = Math.round(presetList[presetId][11] * (presetList[presetId][8] / 255));
            document.querySelector(".scene_section").querySelector(".scene_wrapper:nth-child(" + presetId + ")").querySelector(".scene_inner_wrapper").querySelector(".scene_large_button").style.background = `linear-gradient(to right, rgb(${dimmedR1}, ${dimmedG1}, ${dimmedB1}) 0%, rgb(${dimmedR1}, ${dimmedG1}, ${dimmedB1}) 33.33%, rgb(${dimmedR2}, ${dimmedG2}, ${dimmedB2}) 33.33%, rgb(${dimmedR2}, ${dimmedG2}, ${dimmedB2}) 66.66%, rgb(${dimmedR3}, ${dimmedG3}, ${dimmedB3}) 66.66%, rgb(${dimmedR3}, ${dimmedG3}, ${dimmedB3}) 100%)`;

        }

        //Set the preset
        function setPreset(presetId)
        {
            console.log("Preset : ", presetId);
            for (let i = 1; i < 13; i++) {
                updateChannel(i, presetList[presetId][i-1]);
            }
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[1] + ")").querySelector(".slider_container").querySelector(".white_slider").value = presetList[presetId][0]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[2] + ")").querySelector(".slider_container").querySelector(".red_slider").value = presetList[presetId][1]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[3] + ")").querySelector(".slider_container").querySelector(".green_slider").value = presetList[presetId][2]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[4] + ")").querySelector(".slider_container").querySelector(".blue_slider").value = presetList[presetId][3]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[5] + ")").querySelector(".slider_container").querySelector(".white_slider").value = presetList[presetId][4]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[6] + ")").querySelector(".slider_container").querySelector(".red_slider").value = presetList[presetId][5]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[7] + ")").querySelector(".slider_container").querySelector(".green_slider").value = presetList[presetId][6]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[8] + ")").querySelector(".slider_container").querySelector(".blue_slider").value = presetList[presetId][7];
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[9] + ")").querySelector(".slider_container").querySelector(".white_slider").value = presetList[presetId][8]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[10] + ")").querySelector(".slider_container").querySelector(".red_slider").value = presetList[presetId][9]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[11] + ")").querySelector(".slider_container").querySelector(".green_slider").value = presetList[presetId][10]; 
            document.querySelector(".slider_section").querySelector(".slider_wrapper:nth-child(" + Channel_items[12] + ")").querySelector(".slider_container").querySelector(".blue_slider").value = presetList[presetId][11]; 


        }

        //Cleat the Preset values in the ESP32
        function clearPreset(PresetId) {
            savePreset(PresetId,true);
        }
        

        // JS code that will be executed when the page is loaded
        
        
        createSceneButtons("Preset 1");
        createSceneButtons("Preset 2");
        createSceneButtons("Preset 3");
        createSceneButtons("Preset 4");
        createSceneButtons("Preset 5");
        createSceneButtons("Preset 6");
        createSceneButtons("Preset 7");
        createSceneButtons("Preset 8");
        createSceneButtons("Preset 9");
        createSceneButtons("Preset 10");
        createSliderSpacer("Lamp 1");
        createSlider(1, "W", "DMX Ch 1");
        createSlider(2, "R", "DMX Ch 2");
        createSlider(3, "G", "DMX Ch 3");
        createSlider(4, "B", "DMX Ch 4");
        createSliderSpacer("Lamp 2");
        createSlider(5, "W", "DMX Ch 8");
        createSlider(6, "R", "DMX Ch 9");
        createSlider(7, "G", "DMX Ch 10");
        createSlider(8, "B", "DMX Ch 11");
        createSliderSpacer("Lamp 3");
        createSlider(9, "W", "DMX Ch 15");
        createSlider(10, "R", "DMX Ch 16");
        createSlider(11, "G", "DMX Ch 17");
        createSlider(12, "B", "DMX Ch 18");
    </script>
</body>

</html>)rawliteral";

#endif