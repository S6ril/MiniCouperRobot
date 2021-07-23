#include "http_server.h"
#include "json_interpreter.h"

// A décommenter et inserer vos identifiants
// const char *ssid = "...";
// const char *password = "...";

// Ma configuration des identifiants
#include "credential.h"

#include "pin_configuration.h"
Car_Motion car = Car_Motion(gauche_pin, droite_pin, accelerer_pin, reculer_pin);

AsyncWebServer server(80); // start get_post_server listening on port 80

void setup()
{
    // Définition des pins pour l'objet car
    car.begin();
    // Début de la communication Serial
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    int number_delay = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("...");
    }

    Serial.print("WiFi connected with IP: ");
    Serial.println(WiFi.localIP());

    // Remember to configure the previous server
    setup_http_server(&server, &car); // starts the asyncronus https server*/
    server.begin(); // starts asyncrhonus controller
}

void loop()
{
    delay(1000);
}
