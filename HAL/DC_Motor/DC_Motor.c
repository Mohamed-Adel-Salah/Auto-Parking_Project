/*
 * DC_Motor.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Owner
 */

#include "main.h"
#include "gpio.h"
#include "tim.h"

uint8_t STATE ;


  void move_Forward (void)
  {
	  HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_RESET);
	  //HAL_Delay(10000);
  }



  void move_backward (void)
  {
	  HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_SET);
	 // HAL_Delay(10000);
  }

  void turn_right_forward (void)
  {
	  HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
	  //HAL_Delay(10000);
//	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
  }

  void turn_right_backward (void)
  {
	  HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
//	  	  //HAL_Delay(10000);
//	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
  }

  void turn_left_forward (void)
  {
	  HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_SET);
	  //HAL_Delay(1000);
//	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
  }

  void turn_left_backward (void)
  {
	  HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_SET);
	  //HAL_Delay(1000);
//	  HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
  }

  void stop (void)
  {
	  /*Motor1 Stop*/
	  	   	HAL_GPIO_WritePin(MOTOR1_GPIO_Port, MOTOR1_Pin, GPIO_PIN_RESET);
	  	   	HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, GPIO_PIN_RESET);
	  //
	  //		/*Motor2 Stop*/
	  		HAL_GPIO_WritePin(MOTOR2_GPIO_Port, MOTOR2_Pin, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, GPIO_PIN_RESET);
	       //HAL_Delay(5000);
  }


  void SET_PULSE(uint32_t pulse)
  {

  	TIM_OC_InitTypeDef sConfig = {
  			.OCMode = TIM_OCMODE_PWM1,
  			.Pulse = pulse,
  			.OCPolarity = TIM_OCPOLARITY_HIGH,
  			.OCNPolarity = TIM_OCNPOLARITY_HIGH,
  			.OCFastMode = TIM_OCFAST_DISABLE,
  			.OCIdleState = TIM_OCIDLESTATE_RESET,
  			.OCNIdleState = TIM_OCNIDLESTATE_RESET
  	};

  	HAL_TIM_PWM_Init(&htim5);
  	HAL_TIM_PWM_ConfigChannel(&htim5,&sConfig,TIM_CHANNEL_2);
  	HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2 );

  }

