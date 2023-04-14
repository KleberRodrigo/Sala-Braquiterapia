"""my_controller controller."""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot, Motor

# create the Robot instance.
robot = Robot()

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())
motor1 = robot.getDevice('motor_braco5')

while robot.step(timestep) != -1:
    motor1.setVelocity(1)
    motor1.setPosition(float('+inf'))

# Enter here exit cleanup code.