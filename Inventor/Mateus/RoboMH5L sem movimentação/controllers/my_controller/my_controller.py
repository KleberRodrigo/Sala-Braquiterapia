"""my_controller controller."""
from controller import Robot, Motor

# create the Robot instance.
robot = Robot()

# get the time step of the current world.
timestep = int(robot.getBasicTimeStep())
motor1 = robot.getDevice('motor_braco1')

while robot.step(timestep) != -1:
    motor1.setVelocity(0.1)
    motor1.setPosition(float('+inf'))

# Enter here exit cleanup code.