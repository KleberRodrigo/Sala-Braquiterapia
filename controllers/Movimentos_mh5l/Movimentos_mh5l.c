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

   WbDeviceTag SP1 =  wb_robot_get_device("SP1");
   WbDeviceTag SP2 =  wb_robot_get_device("SP2");
   WbDeviceTag SP3 =  wb_robot_get_device("SP3");
   WbDeviceTag SP4 =  wb_robot_get_device("SP4");
   WbDeviceTag SP5 =  wb_robot_get_device("SP5");
   
   wb_position_sensor_enable(SP1, TIME_STEP);
   wb_position_sensor_enable(SP2, TIME_STEP);
   wb_position_sensor_enable(SP3, TIME_STEP);
   wb_position_sensor_enable(SP4, TIME_STEP);
   wb_position_sensor_enable(SP5, TIME_STEP);
   
   WbDeviceTag F1 = wb_robot_get_device("F1");
   WbDeviceTag F2 = wb_robot_get_device("F2");
   WbDeviceTag F3 = wb_robot_get_device("F3");
   WbDeviceTag F4 = wb_robot_get_device("F4");
   WbDeviceTag F5 = wb_robot_get_device("F5");
   
   WbDeviceTag M1 = wb_robot_get_device("M1");
   WbDeviceTag M2 = wb_robot_get_device("M2");
   WbDeviceTag M3 = wb_robot_get_device("M3");
   WbDeviceTag M4 = wb_robot_get_device("M4");
   WbDeviceTag M5 = wb_robot_get_device("M5");
 
   int vel = 1;
   wb_motor_set_velocity(M1, vel);
   wb_motor_set_velocity(M2, vel);
   wb_motor_set_velocity(M3, vel);
   wb_motor_set_velocity(M4, vel); 
   wb_motor_set_velocity(M5, vel);
   
   double Sensor_Posicao_1 = 0;
   double Sensor_Posicao_2 = 0;
   double Sensor_Posicao_3 = 0;
   double Sensor_Posicao_4 = 0;
   double Sensor_Posicao_5 = 0;
  
   wb_keyboard_enable(TIME_STEP);
   
   float posicao1 = 0.0;
   float posicao2 = -1.0;
   float posicao3 = 2.0;
   float posicao4 = 0.0;
   float posicao5 = 0.5;
 
   int key = -1;
   int key_aux = -1;
   int motor = 1;
   float step_arm = 0.005;
   
 /*
   Variaveis de Posição*/
   
   float Pos[4][5]={{0.150000,1.220000,0.500001,0.000000,0.550000},
                    {0.150000,1.290000,0.700001,0.000000,0.250000},
                    {-0.135000,1.455000,0.250001,0.000000,0.500000},
                    {-0.135000,1.540000,0.250001,0.000000,0.500000}};
   
 //*/
   
void Posicao_inicial()
{
       posicao1 = 0.0;
       posicao2 = -1.0;
       posicao3 = 2.0;
       posicao4 = 0.0;
       posicao5 = 0.5;
       wb_motor_set_position(M1,  posicao1);
       wb_motor_set_position(M2,  posicao2);
       wb_motor_set_position(M3,  posicao3);
       wb_motor_set_position(M4,  posicao4);
       wb_motor_set_position(M5,  posicao5);
}

  
  while (wb_robot_step(TIME_STEP) != -1) {
    
    key_aux =  wb_keyboard_get_key();
    if(key_aux == key)//{
      key = -1;
      //printf("Valor da key = %d\n",key);}
    else {
      key = key_aux;
      printf("\n\nValor da key = %d",key);
      printf("\nValor do motor = %d\n",motor);}
      
 
    if ((key >= 0)) {
      switch (key) {
        case '1':
          motor = 1;
          break;
        case '2':
          motor = 2;
          break;
        case '3':
          motor = 3;
          break;
        case '4':
          motor = 4;
          break;
        case '5':
          motor = 5;
          break;
        case 73:
          Posicao_inicial();
          break;
        case WB_KEYBOARD_UP:
          if(motor == 1){
          printf("Rodando braco 1 horario \n");
          posicao1 = posicao1 - step_arm;
          wb_motor_set_position(M1,posicao1);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 2){
          printf("Rodando braco 2 horario \n");
          posicao2 = posicao2 - step_arm;
          wb_motor_set_position(M2,posicao2);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 3){
          printf("Rodando braco 3 horario \n");
          posicao3 = posicao3 - step_arm;
          wb_motor_set_position(M3,posicao3);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 4){
          printf("Rodando braco 4 horario \n");
          posicao4 = posicao4 - step_arm;
          wb_motor_set_position(M4,posicao4);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 5){
          printf("Rodando braco 5 horario \n");
          posicao5 = posicao5 - step_arm;
          wb_motor_set_position(M5,posicao5);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          break;
          
        case 85:
          step_arm = 0.05;
          break;
          
        case 68:
          step_arm = 0.005;
          break;
          
          
        case WB_KEYBOARD_DOWN:
          if(motor == 1){
          printf("Rodando braco 1 antihorario \n");
          posicao1 = posicao1 + step_arm;
          wb_motor_set_position(M1,posicao1);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 2){
          printf("Rodando braco 2 antihorario \n");
          posicao2 = posicao2 + step_arm;
          wb_motor_set_position(M2,posicao2);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 3){
          printf("Rodando braco 3 antihorario \n");
          posicao3 = posicao3 + step_arm;
          wb_motor_set_position(M3,posicao3);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 4){
          printf("Rodando braco 4 antihorario \n");
          posicao4 = posicao4 + step_arm;
          wb_motor_set_position(M4,posicao4);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          
          if(motor == 5){
          printf("Rodando braco 5 antihorario \n");
          posicao5 = posicao5 + step_arm;
          wb_motor_set_position(M5,posicao5);
          printf("\nPos=[%f,%f,%f,%f,%f]",posicao1, posicao2, posicao3, posicao4, posicao5);}
          break;
          
         case 65:
         
         while(1){
            wb_motor_set_position(M1,Pos[0][0]);
            wb_motor_set_position(M2,Pos[0][1]);
            wb_motor_set_position(M3,Pos[0][2]);
            wb_motor_set_position(M4,Pos[0][3]);
            wb_motor_set_position(M5,Pos[0][4]);
            
            wb_robot_step(4000);
            
            wb_motor_set_position(M1,Pos[1][0]);
            wb_motor_set_position(M2,Pos[1][1]);
            wb_motor_set_position(M3,Pos[1][2]);
            wb_motor_set_position(M4,Pos[1][3]);
            wb_motor_set_position(M5,Pos[1][4]);
            
            wb_robot_step(4000);
            
            wb_motor_set_position(M1,Pos[0][0]);
            wb_motor_set_position(M2,Pos[0][1]);
            wb_motor_set_position(M3,Pos[0][2]);
            wb_motor_set_position(M4,Pos[0][3]);
            wb_motor_set_position(M5,Pos[0][4]);
            
            wb_robot_step(4000);
            
            wb_motor_set_position(M1,Pos[2][0]);
            wb_motor_set_position(M2,Pos[2][1]);
            wb_motor_set_position(M3,Pos[2][2]);
            wb_motor_set_position(M4,Pos[2][3]);
            wb_motor_set_position(M5,Pos[2][4]);
            
            wb_robot_step(4000);
            
            wb_motor_set_position(M1,Pos[3][0]);
            wb_motor_set_position(M2,Pos[3][1]);
            wb_motor_set_position(M3,Pos[3][2]);
            wb_motor_set_position(M4,Pos[3][3]);
            wb_motor_set_position(M5,Pos[3][4]);
            
            wb_robot_step(4000);
            
            wb_motor_set_position(M1,Pos[2][0]);
            wb_motor_set_position(M2,Pos[2][1]);
            wb_motor_set_position(M3,Pos[2][2]);
            wb_motor_set_position(M4,Pos[2][3]);
            wb_motor_set_position(M5,Pos[2][4]);
            
            wb_robot_step(4000);
           }
          break;
          
        }
 }};

   wb_robot_cleanup();

   return 0;
}