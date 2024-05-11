@echo off
(
ECHO #ifndef HTML_CODE_H
ECHO #define HTML_CODE_H
ECHO const char Html_code[] PROGMEM = R"rawliteral(
) > "Html_code.h"

copy Html_code.h+Html_code.html Html_code.h

(
ECHO ^)rawliteral";
ECHO #endif
) >> "Html_code.h"
echo done!
pause
