"""Código para movimentar o robo MH5L através das teclas do teclado"""
# import cv2 as cv 
# import numpy as np
# import json
from lib.controller import Robot, Motor, Keyboard, Camera
# from lib.controller import Camera

# create the Robot instance.

dispositivo_caixa = Robot()
teclado = Keyboard()
# get the time step of the current world.

timestep2 = int(dispostivo_caixa.getBasicTimeStep())
teclado.enable(timestep2)

#Definindo os motores do robo:
motor6 = dispostivo_caixa.getDevice('motor_caixa')

"""
Teclas para movimentação:
    N -> Fecha a caixa
    M -> abre a caixa
"""

while robot.step(timestep) != -1:
    key = teclado.getKey()

    if key == 77:
        motor6.setVelocity(0.1)
        motor6.setPosition(float('+inf'))
    elif key == 78:
        motor6.setVelocity(-0.1)
        motor6.setPosition(float('+inf'))
    else:
        continue

