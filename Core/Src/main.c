/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DC_Motor.h"
#include "FreeRTOSConfig.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint16_t IC_Val1[3], IC_Val2[3] , Difference[3];
uint8_t count = 0, Trigger_ID = 0;
uint8_t Distance[3] = {0};


uint16_t Counter=0,C1=0,C2=0,C3=0,C4=0,C5=0;

uint8_t right_backward_flag=0, right_forward_flag=0, FLAG=5, Stop_Flag=0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

void Start_Trigger(void);

void Mossion_Decision(void);

void Start_Searching(void);

void Search_for_Slot(void);

void Move_Till_Next_Car(void);

void Start_Parking(void);

void Park(void);

void _delay_ms(uint32_t ticks);


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */

	HAL_TIM_Base_Start(&htim1);
	/*Start ICU for timer1 CH1*/
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
	/*Start ICU for timer3 CH2*/
	HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
	/*Start ICU for timer4 CH1*/
	HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);

	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);

//	HAL_UART_Receive_IT(&huart1, &STATE, sizeof(uint8_t));
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{

/********************* Without RTOS ******************************/
//		Start_Trigger();
//
//  		if (STATE == Auto_Parking)
//  		{
//  			FLAG=0;
//  		}
//
//		if(FLAG==5)
//		{
//			Mossion_Decision();
//		}
//		else if(FLAG==0)
//		{
//			Start_Searching();
//		}
//		else if(FLAG==1)
//		{
//			Search_for_Slot();
//		}
//		else if(FLAG==2)
//		{
//			Move_Till_Next_Car();
//		}
//		else if(FLAG==3)
//		{
//			Start_Parking();
//		}
//		else if(FLAG==4)
//		{
//			Park();
//		}


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (  (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) )  // if the interrupt source is channel1
	{
		if(Trigger_ID==0)
		{

			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
		}
		else if(Trigger_ID==1)
		{
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
		}
		else if(Trigger_ID==2)
		{
			HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);
		}


		if (count==0) // if the first value is not captured
		{

			IC_Val1[Trigger_ID] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
			count = 1;
		}

		else if (count==1)   // if the first is already captured
		{
			IC_Val2[Trigger_ID] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim,0);	// Reset Timer Count

			/*Distance Calculation*/
			if(IC_Val2[Trigger_ID] > IC_Val1[Trigger_ID]){
				Difference[Trigger_ID]=IC_Val2[Trigger_ID]-IC_Val1[Trigger_ID];
				Distance[Trigger_ID]=Difference[Trigger_ID]/58;
			}

			Trigger_ID++;

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			count =0;
		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart1, &STATE, sizeof(uint8_t));
}

void Start_Trigger(void)
{
	if(Trigger_ID >= 3)
	{
		Trigger_ID = 0;
	}
	else if(Trigger_ID==0)
	{
		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
	}
	else if(Trigger_ID==1)
	{
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	}
	else if(Trigger_ID==2)
	{
		HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	}

}

void Mossion_Decision(void)
{
	if (STATE == Stop)
	{
		stop();
	}
	   else  if(STATE == Forward)
	{
		move_Forward();
	}
	else if(STATE == Backward)
	{
		move_backward();
	}
	else if (STATE == Turn_rightforward)
	{
		turn_right_forward();
	}
	else if (STATE == Turn_rightbackward)
	{
		turn_right_backward();
	}
	else if (STATE == Turn_leftforward)
	{
		turn_left_forward();
	}
	else if (STATE == Turn_leftbackward)
	{
		turn_left_backward();
	}
}

void Start_Searching(void)
{

		if( (Distance[2]<20)  || (Distance[1]<20))
		{
			Counter++;
			if(Counter == 10)
			{
				move_Forward();
				Counter=0;
			}
		}
		else
		{
			Counter=0;
		}
		FLAG=1;
}

void Search_for_Slot(void)
{
	if( (Distance[2]>20) && (Distance[1]>20) )
	{
		Counter++;
		if(Counter == 10)
		{
//				stop();
//				HAL_Delay(5000);

			FLAG =2;
			Counter=0;
			move_Forward();
		}
	}
	else
	{
		Counter=0;
	}

}

void Move_Till_Next_Car(void)
{
		if( (Distance[2]<20) && (Distance[1]<20) )
		{
			Counter++;
			if(Counter == 10)
			{
				FLAG=3;
				Counter=0;
			}
		}
		else
		{
			Counter=0;
		}
}

void Start_Parking(void)
{
		SET_PULSE(45000);
		move_backward();
//		_delay_ms(400);
		HAL_Delay(400);
		stop();
		HAL_Delay(5000);
		turn_right_backward();

		FLAG=4;
}

void Park(void)
{
		if( ( (Distance[1])<20 ) && ( Stop_Flag==1 ) )
		{
			C4++;
			if(C4==10)
			{
				stop();
				while(1);
			}
		}

		if( (Distance[0]>20) && (right_forward_flag==1) )
		{
			C3++;
			if(C3==10)
			{
				turn_left_backward();
				Stop_Flag=1;
			}
		}
		else if( (Distance[0]<25) )
		{
			C2++;
			if(C2==10)
			{
				turn_right_forward();
				C2=0;
				right_backward_flag=1;
				right_forward_flag=1;
			}
		}
		else
		{
			C2=0;
			C3=0;
			C4=0;
		}
}

void _delay_ms(uint32_t ticks)
{
	uint32_t i;
	for (i =0; i<(ticks*500) ; i++)
	{
		asm("NOP");
	}
}


/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
