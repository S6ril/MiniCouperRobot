#include "Arduino.h"
#pragma once

class Car_Motion
{
private:
    int _pin_gauche;
    int _pin_droite; 
    int _pin_acc; 
    int _pin_rec;

    int _channel_gauche = 0;
    int _channel_droite = 1;
    int _channel_acc = 2;
    int _channel_rec = 3;
    

    const int _resolution = 8;
    const int _freq = 20000;

public : 
    Car_Motion(int pin_gauche, int pin_droite, int pin_acc, int pin_rec);
    void begin();
    void stop();

    void avancer(double vitesse);
    void reculer(double vitesse);

    void droite(double valeur);
    void gauche(double valeur);
};
