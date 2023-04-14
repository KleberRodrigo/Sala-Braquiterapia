#include <stdio.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/position_sensor.h>
#include <time.h>

#define TIME_STEP 64

int main(int argc, char **argv) 
{
  wb_robot_init();
  
    WbDeviceTag motor;
    motor= wb_robot_get_device("motor_caixa");
    wb_motor_set_position(motor,2);
 
 
  wb_robot_cleanup();

  return 0;
}
