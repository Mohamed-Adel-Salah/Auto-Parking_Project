/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
#include "tim.h"
#include "gpio.h"
#include "DC_Motor.h"
#include "stdio.h"
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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;
osThreadId myTask04Handle;
osThreadId START_SEARCHINGHandle;
osThreadId SEARCH_FOR_SLOTHandle;
osThreadId MOVE_TILL_NEXT_Handle;
osThreadId START_PARKINGHandle;
osThreadId PARKHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void Bluetooth(void const * argument);
void Utrasonic(void const * argument);
void start_searching(void const * argument);
void search_for_slot(void const * argument);
void move_till_next_car(void const * argument);
void start_parking(void const * argument);
void park(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityNormal, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, Bluetooth, osPriorityIdle, 0, 128);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* definition and creation of myTask04 */
  osThreadDef(myTask04, Utrasonic, osPriorityIdle, 0, 128);
  myTask04Handle = osThreadCreate(osThread(myTask04), NULL);

  /* definition and creation of START_SEARCHING */
  osThreadDef(START_SEARCHING, start_searching, osPriorityIdle, 0, 128);
  START_SEARCHINGHandle = osThreadCreate(osThread(START_SEARCHING), NULL);

  /* definition and creation of SEARCH_FOR_SLOT */
  osThreadDef(SEARCH_FOR_SLOT, search_for_slot, osPriorityIdle, 0, 128);
  SEARCH_FOR_SLOTHandle = osThreadCreate(osThread(SEARCH_FOR_SLOT), NULL);

  /* definition and creation of MOVE_TILL_NEXT_ */
  osThreadDef(MOVE_TILL_NEXT_, move_till_next_car, osPriorityIdle, 0, 128);
  MOVE_TILL_NEXT_Handle = osThreadCreate(osThread(MOVE_TILL_NEXT_), NULL);

  /* definition and creation of START_PARKING */
  osThreadDef(START_PARKING, start_parking, osPriorityIdle, 0, 128);
  START_PARKINGHandle = osThreadCreate(osThread(START_PARKING), NULL);

  /* definition and creation of PARK */
  osThreadDef(PARK, park, osPriorityIdle, 0, 128);
  PARKHandle = osThreadCreate(osThread(PARK), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */

	STATE=Stop;
	SET_PULSE(20000);


	for(;;)
	{
//		osThreadSuspend(defaultTaskHandle);
//		osThreadSuspend(myTask04Handle);

		osDelay(100);
	}
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval Non
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for(;;)
  {
		if(FLAG==5)
		{
			Mossion_Decision();
		}

  		if (STATE == Auto_Parking)
  		{
  			FLAG=0;
  		}
    osDelay(90);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_Bluetooth */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Bluetooth */
void Bluetooth(void const * argument)
{
  /* USER CODE BEGIN Bluetooth */
  /* Infinite loop */
  for(;;)
  {
	  HAL_UART_Receive(&huart1, &STATE, 1, 1000);
	  HAL_UART_Transmit(&huart1, &STATE, 1, 1000);

    osDelay(100);
  }
  /* USER CODE END Bluetooth */
}

/* USER CODE BEGIN Header_Utrasonic */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Utrasonic */
void Utrasonic(void const * argument)
{
  /* USER CODE BEGIN Utrasonic */
  /* Infinite loop */
  for(;;)
  {
	  Start_Trigger();

    osDelay(90);
  }
  /* USER CODE END Utrasonic */
}

/* USER CODE BEGIN Header_start_searching */
/**
* @brief Function implementing the START_SEARCHING thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_searching */
void start_searching(void const * argument)
{
  /* USER CODE BEGIN start_searching */
  /* Infinite loop */
  for(;;)
  {
		if(FLAG==0)
		{
			Start_Searching();
		}

    osDelay(90);
  }
  /* USER CODE END start_searching */
}

/* USER CODE BEGIN Header_search_for_slot */
/**
* @brief Function implementing the SEARCH_FOR_SLOT thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_search_for_slot */
void search_for_slot(void const * argument)
{
  /* USER CODE BEGIN search_for_slot */
  /* Infinite loop */
  for(;;)
  {
		if(FLAG==1)
		{
			Search_for_Slot();
		}

    osDelay(90);
  }
  /* USER CODE END search_for_slot */
}

/* USER CODE BEGIN Header_move_till_next_car */
/**
* @brief Function implementing the MOVE_TILL_NEXT_ thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_move_till_next_car */
void move_till_next_car(void const * argument)
{
  /* USER CODE BEGIN move_till_next_car */
  /* Infinite loop */
  for(;;)
  {
		if(FLAG==2)
		{
			Move_Till_Next_Car();
		}

    osDelay(90);
  }
  /* USER CODE END move_till_next_car */
}

/* USER CODE BEGIN Header_start_parking */
/**
* @brief Function implementing the START_PARKING thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_parking */
void start_parking(void const * argument)
{
  /* USER CODE BEGIN start_parking */
  /* Infinite loop */
  for(;;)
  {
		if(FLAG==3)
		{
			Start_Parking();
		}

    osDelay(90);
  }
  /* USER CODE END start_parking */
}

/* USER CODE BEGIN Header_park */
/**
* @brief Function implementing the PARK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_park */
void park(void const * argument)
{
  /* USER CODE BEGIN park */
  /* Infinite loop */
  for(;;)
  {
		if(FLAG==4)
		{
			Park();
		}

    osDelay(90);
  }
  /* USER CODE END park */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
