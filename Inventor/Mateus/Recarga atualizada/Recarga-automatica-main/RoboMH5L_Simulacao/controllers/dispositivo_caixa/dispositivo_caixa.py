"""Código para movimentar o robo MH5L através das teclas do teclado"""
import cv2 as cv 
import numpy as np
import json
from controller 
import Robot
import  Motor
import Keyboard 
import Camera
# from lib.controller import Camera

# create the Robot instance.

dispositivo = Robot()
teclado1 = Keyboard()
# get the time step of the current world.

timestep = int(dispositivo.getBasicTimeStep())
teclado1.enable(timestep)

#Definindo os motores do robo:
motor6 = dispositivo.getDevice('motor_caixa')

"""
Teclas para movimentação:
    L -> Fecha a caixa
    K -> abre a caixa
"""

while dispositivo.step(timestep) != -1:
    key1 = teclado1.getKey()
    print('funcionando')
    if key1 == 75:
        motor6.setVelocity(0.5)
        motor6.setPosition(float('+inf'))
        print('to aqui')
    elif key1 == 76:
        motor6.setVelocity(-0.5)
        motor6.setPosition(float('+inf'))
    else:
        pass

