#include "car_motion.h"

Car_Motion::Car_Motion(int pin_gauche, int pin_droite, int pin_acc, int pin_rec)
{
    _pin_gauche = pin_gauche;
    _pin_droite = pin_droite;
    _pin_acc    = pin_acc;
    _pin_rec    = pin_rec;
}


void Car_Motion::begin()
{
    // Begin pwm for all pin
    for (int channel = 0; channel < 4; channel ++)
    {
        ledcSetup(channel, _freq, _resolution);
    }
    ledcAttachPin(_pin_gauche, _channel_gauche);
    ledcAttachPin(_pin_droite, _channel_droite);
    ledcAttachPin(_pin_acc,    _channel_acc);
    ledcAttachPin(_pin_rec,    _channel_rec);
}

void Car_Motion::avancer(double vitesse)
{
    ledcWrite(_channel_acc, abs(vitesse * 255));
}

void Car_Motion::stop()
{
    ledcWrite(_channel_acc, 0);
    ledcWrite(_channel_rec, 0);
}

void Car_Motion::reculer(double vitesse)
{
    ledcWrite(_channel_rec, abs(vitesse * 255));
}

void Car_Motion::droite(double valeur)
{
    ledcWrite(_channel_droite, valeur*240);
}

void Car_Motion::gauche(double valeur)
{
    ledcWrite(_channel_gauche, valeur*240);
}

