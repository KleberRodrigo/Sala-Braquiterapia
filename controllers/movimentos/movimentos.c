/*
 * File:          MH5L.c
 * Date:          10/02/2023
 * Description:   FIRMWARE TESTE DE MOVIMENTOS 
 * Author:        KLEBER JUNIOR
 * Modifications: INICIANDO TESTES
 */

#include <stdio.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/position_sensor.h>
#include <math.h>
#include <time.h>
#include <webots/keyboard.h>

#define TIME_STEP 64

int main(int argc, char **argv) {

   wb_robot_init();
   
   WbDeviceTag M1 = wb_robot_get_device("M1");
   WbDeviceTag M2 = wb_robot_get_device("M2");
   WbDeviceTag M3 = wb_robot_get_device("M3");
   WbDeviceTag M4 = wb_robot_get_device("M4");
   WbDeviceTag M5 = wb_robot_get_device("M5");
 
   double vel = 0.3;
   wb_motor_set_velocity(M1, vel);
   wb_motor_set_velocity(M2, vel);
   wb_motor_set_velocity(M3, vel);
   wb_motor_set_velocity(M4, vel); 
   wb_motor_set_velocity(M5, vel);
   
   float posicao1 = 0.0;
   float posicao2 = -1.0;
   float posicao3 = 2.0;
   float posicao4 = 0.0;
   float posicao5 = 0.5;
   
 /*
   Variaveis de Posição*/
   
   float Pos[4][5]={{0.150000,1.220000,0.500001,0.000000,0.550000},
                    {0.150000,1.290000,0.700001,0.000000,0.250000},
                    {-0.135000,1.455000,0.250001,0.000000,0.500000},
                    {-0.135000,1.540000,0.250001,0.000000,0.500000}};
   
 //*


            wb_motor_set_position(M1,Pos[0][0]);
            wb_motor_set_position(M2,Pos[0][1]);
            wb_motor_set_position(M3,Pos[0][2]);
            wb_motor_set_position(M4,Pos[0][3]);
            wb_motor_set_position(M5,Pos[0][4]);
            wb_robot_step(4000);
  
  while (wb_robot_step(TIME_STEP) != -1) {
  
            wb_motor_set_position(M1,Pos[0][0]);
            wb_motor_set_position(M2,Pos[0][1]);
            wb_motor_set_position(M3,Pos[0][2]);
            wb_motor_set_position(M4,Pos[0][3]);
            wb_motor_set_position(M5,Pos[0][4]);
            
            wb_robot_step(2000);
            
            wb_motor_set_position(M5,Pos[1][4]);
            wb_robot_step(1000);
            wb_motor_set_position(M1,Pos[1][0]);
            wb_motor_set_position(M2,Pos[1][1]);
            wb_motor_set_position(M3,Pos[1][2]);
            wb_motor_set_position(M4,Pos[1][3]);
            
            
            wb_robot_step(2000);
            
            wb_motor_set_position(M1,Pos[0][0]);
            wb_motor_set_position(M2,Pos[0][1]);
            wb_motor_set_position(M3,Pos[0][2]);
            wb_motor_set_position(M4,Pos[0][3]);
            wb_motor_set_position(M5,Pos[0][4]);
            
            wb_robot_step(2000);
            
            wb_motor_set_position(M1,Pos[2][0]);
            wb_motor_set_position(M2,Pos[2][1]);
            wb_motor_set_position(M3,Pos[2][2]);
            wb_motor_set_position(M4,Pos[2][3]);
            wb_motor_set_position(M5,Pos[2][4]);
            
            wb_robot_step(2000);
            
            wb_motor_set_position(M1,Pos[3][0]);
            wb_motor_set_position(M2,Pos[3][1]);
            wb_motor_set_position(M3,Pos[3][2]);
            wb_motor_set_position(M4,Pos[3][3]);
            wb_motor_set_position(M5,Pos[3][4]);
            
            wb_robot_step(2000);
            
            wb_motor_set_position(M1,Pos[2][0]);
            wb_motor_set_position(M2,Pos[2][1]);
            wb_motor_set_position(M3,Pos[2][2]);
            wb_motor_set_position(M4,Pos[2][3]);
            wb_motor_set_position(M5,Pos[2][4]);
            
            wb_robot_step(2000);
   
  };

  wb_robot_cleanup();

  return 0;
}
