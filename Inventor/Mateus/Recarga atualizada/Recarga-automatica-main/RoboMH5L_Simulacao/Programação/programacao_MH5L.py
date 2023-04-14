"""Código para movimentar o robo MH5L através das teclas do teclado"""
import cv2 as cv 
import numpy as np
import json
from lib.controller import Robot, Motor, Keyboard, Camera
# from lib.controller import Camera

# create the Robot instance.
robot = Robot()
# dispositivo_caixa = Robot()
teclado = Keyboard()
camera1 = Camera('camera')

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())
# timestep2 = int(dispostivo_caixa.getBasicTimeStep())
teclado.enable(timestep)
camera1.enable(timestep)


max_lowThreshold = 100
window_name = 'Edge Map'
title_trackbar = 'Min Threshold:'
ratio = 3
kernel_size = 3


def obter_img(camera):
    img = np.array(camera.getImageArray(), dtype=np.uint8)
    img = cv.cvtColor(img, cv.COLOR_BGRA2RGB)
    img = cv.rotate(img, cv.ROTATE_90_CLOCKWISE)
    img = cv.flip(img, 1)
    
    return img


cv.namedWindow('output', cv.WINDOW_NORMAL)
cv.startWindowThread()


#Definindo os motores do robo:
motor1 = robot.getDevice('motor_braco1')
motor2 = robot.getDevice('motor_braco2')
motor3 = robot.getDevice('motor_braco3')
motor4 = robot.getDevice('motor_braco4')
motor5 = robot.getDevice('motor_braco5')
# motor6 = dispostivo_caixa.getDevice('motor_caixa')

"""
Teclas para movimentação:
    A -> movimenta axis-2 para esquerda
    D -> movimenta axis-2 para direita
    W -> movimenta axis-1 no sentido anti-horário
    S -> movimenta axis-1 no sentido horário
    C -> movimenta axis-3 no sentido horário
    V -> movimenta axis-3 no sentido anti-horário
    F -> movimenta axis-4 no sentido horário
    G -> movimenta axis-4 no sentido anti-horário
    T -> movimenta axis-4 no sentido horário
    Y -> movimenta axis-4 no sentido anti-horário
    1 -> desliga o motor 1
    2 -> desliga o motor 2
    3 -> desliga o motor 3
    4 -> desliga o motor 4
    5 -> desliga o motor 5
    M -> abre a caixa
"""

while robot.step(timestep) != -1:
    key = teclado.getKey()

    imagem = obter_img(camera1)
    cv.imshow('output', imagem)
    cv.waitKey(16)

    if key == 65:
        motor1.setVelocity(0.1)
        motor1.setPosition(float('+inf'))          
    elif key == 68:
        motor1.setVelocity(-0.1)
        motor1.setPosition(float('+inf'))
    elif key == 87:
        motor2.setVelocity(0.1)
        motor2.setPosition(float('+inf'))
    elif key == 83:
        motor2.setVelocity(-0.1)
        motor2.setPosition(float('+inf'))
    elif key == 86:
        motor3.setVelocity(0.1)
        motor3.setPosition(float('+inf'))
    elif key == 67:
        motor3.setVelocity(-0.1)
        motor3.setPosition(float('+inf'))
    elif key == 70:
        motor4.setVelocity(0.1)
        motor4.setPosition(float('+inf'))
    elif key == 71:
        motor4.setVelocity(-0.1)
        motor4.setPosition(float('+inf'))
    elif key == 84:
        motor5.setVelocity(0.1)
        motor5.setPosition(float('+inf'))
    elif key == 89:
        motor5.setVelocity(-0.1)
        motor5.setPosition(float('+inf')) 
    # elif key == 77:
    #     motor6.setVelocity(0.1)
    #     motor6.setPosition(float('+inf'))
    # elif key == 78:
    #     motor6.setVelocity(-0.1)
    #     motor6.setPosition(float('+inf'))
    elif key == 49:
        motor1.setVelocity(0)
    elif key == 50:
        motor2.setVelocity(0)
    elif key == 51:
        motor3.setVelocity(0)
    elif key == 52:
        motor4.setVelocity(0)
    elif key == 53:
        motor5.setVelocity(0)
    else:
        continue

