#include "http_server.h"

void setup_http_server(AsyncWebServer* server, Car_Motion *car)
{
    // Example of function that holds and HTTP_GET request on 192.168.4.1:80/get_data
    server->on(
        "/get_data",
        HTTP_GET,
        [](AsyncWebServerRequest *request)
        {
            // Code that holds the request
            Serial.println("Get received"); // Just for debug
            request->send(201, "text/plain", "Here I am");
        });

    // Example of function that holds and HTTP_POST request on 192.168.4.1:80/set_data
    server->on(
        "/set_data",
        HTTP_POST,
        [](AsyncWebServerRequest *request) {},
        NULL,
        [car](AsyncWebServerRequest *request, uint8_t *data, size_t len,
              size_t index, size_t total)
        {
            // Here goes the code to manage the post request
            // The data is received on 'data' variable
            // Parse data
            data_to_action(data, car);
            request->send(200, "text/plain", "1");
        });

    
}