#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"
#include "json_interpreter.h"

#ifndef _HTTP_SERVER_
#define _HTTP_SERVER_

void setup_http_server(AsyncWebServer *server, Car_Motion *car);

#endif
