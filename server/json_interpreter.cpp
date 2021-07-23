#include "json_interpreter.h"

// Attention ne permet pas d'envoyer la donnée 0 mais si la donnée n'est pas reçu, elle est par défaut à 0
void data_to_action(uint8_t *data, Car_Motion *car)
{
    StaticJsonDocument<50> _JSONBuffer;
    deserializeJson(_JSONBuffer, data);
    if (_JSONBuffer.isNull() or _JSONBuffer.containsKey("stop"))
    {
        Serial.println("STOP");
        car->stop();
    }
    else 
    {
        

        double vitesse_avancer = _JSONBuffer["avancer"];
        Serial.print("avancer :");
        Serial.println(vitesse_avancer);
        car->avancer(vitesse_avancer);
        
        double vitesse_reculer = _JSONBuffer["reculer"];
        Serial.print("reculer :"); 
        Serial.println(vitesse_reculer);
        car->reculer(vitesse_reculer);

        
    }
    Serial.print("number :");
    Serial.println((double)_JSONBuffer["number"]);

    double valeur_gauche = _JSONBuffer["gauche"];
    Serial.print("gauche :");
    Serial.println(valeur_gauche);
    car->gauche(valeur_gauche);

    double valeur_droite = _JSONBuffer["droite"];
    Serial.print("droite :");
    Serial.println(valeur_droite);
    car->droite(valeur_droite);

    Serial.println("------------------------------------");
}