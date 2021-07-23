import requests
import time
import pygame
import json

adress_server = "192.168.0.186"


pygame.init()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)
joystick.init()

axes = joystick.get_numaxes()
axis = [0]*axes

buttons = joystick.get_numbuttons()
button = [0]*buttons

try:
    while True:
        data2send = {"stop": 0}

        for event in pygame.event.get():  # User did something.
            if event.type == pygame.JOYBUTTONDOWN:
                # print("Joystick button pressed.")
                pass
            elif event.type == pygame.JOYBUTTONUP:
                # print("Joystick button released.")
                pass
        
        
        seuil = 0.2
        for i in range(axes):
            axis[i] = joystick.get_axis(i)
        # print(axis[:2])
        if axis[0] > seuil:
            data2send["droite"] = 1
        elif axis[0] < -seuil:
            data2send["gauche"] = 1



        for i in range(buttons):
            button[i] = joystick.get_button(i)
        # print(button)
        if button[2] == 1:
            del data2send["stop"]
            data2send["reculer"] = 1
        
        elif button[0] == 1:
            del data2send["stop"]
            data2send["avancer"] = 1
        
        data_request = json.dumps(data2send)
        # print(data_request)
        requests.post('http://' + adress_server + ':80/set_data', data=data_request)

        
        time.sleep(0.01)

except KeyboardInterrupt:
    pygame.quit()


print("Fin Programme")
