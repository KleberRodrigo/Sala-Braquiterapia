#include <stdio.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/position_sensor.h>
#include <webots/touch_sensor.h>
#include <math.h>
#include <time.h>

#define TIME_STEP 32

int main()
{

  wb_robot_init();
    
    WbDeviceTag motor[6];
    motor[0] = wb_robot_get_device("motor1");
    motor[1] = wb_robot_get_device("motor2");
    motor[2] = wb_robot_get_device("motor3");
    motor[3] = wb_robot_get_device("motor4");
    motor[4] = wb_robot_get_device("motor5");
    motor[5] = wb_robot_get_device("motor6");
    
    WbDeviceTag position[6];
    position[0] = wb_robot_get_device("position1");
    position[1] = wb_robot_get_device("position2");
    position[2] = wb_robot_get_device("position3");
    position[3] = wb_robot_get_device("position4");
    position[4] = wb_robot_get_device("position5");
    position[5] = wb_robot_get_device("position6");
           
    for(int i = 0; i<6; i++)
    {
      wb_position_sensor_enable(position[i], TIME_STEP);
      wb_motor_set_position(motor[i], 0);
      wb_motor_set_velocity(motor[i], 1);
    }  
    
    
    while(1)
    {
      wb_motor_set_position(motor[2],-M_PI/4);
      wb_motor_set_position(motor[0],M_PI);
      wb_robot_step(4000);
      wb_motor_set_position(motor[4],-M_PI/4);
      wb_robot_step(2000);
      wb_motor_set_position(motor[1],M_PI/2);
      wb_robot_step(4000);
      wb_motor_set_position(motor[0],0);
      wb_motor_set_position(motor[2],0);
      wb_motor_set_position(motor[4],0);
      wb_motor_set_position(motor[1],0);
      wb_robot_step(4000);
    }
      
  wb_robot_cleanup();

  return 0;
}