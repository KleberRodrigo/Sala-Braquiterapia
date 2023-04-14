from lib.controller import Robot, Motor, Keyboard

# create the Robot instance.
robot = Robot()
teclado = Keyboard()

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())
teclado.enable(timestep)

#Definindo os motores do robo:
motor1 = robot.getDevice('motor_braco1')
motor2 = robot.getDevice('motor_braco2')
motor3 = robot.getDevice('motor_braco3')
motor4 = robot.getDevice('motor_braco4')
motor5 = robot.getDevice('motor_braco5')

while robot.step(timestep) != -1:
    key = teclado.getKey()

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
        motor3.setssVelocity(-0.1)
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
    elif key == 81:
        motor1.setVelocity(0)
        motor2.setVelocity(0)
        motor3.setVelocity(0)
        motor4.setVelocity(0)
        motor5.setVelocity(0)
        
    else:
        continue

