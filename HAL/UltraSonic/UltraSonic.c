#include "main.h"
#include "../../LIB/Delayus.h"
#include "UltraSonic.h"

#define Trigger_Port	GPIOC

void UltrasonicTrigger(uint8_t Trigger_Pin)
{
	HAL_GPIO_WritePin(Trigger_Port, Trigger_Pin, GPIO_PIN_SET);
	delay_us(10); // 10 microseconds
	HAL_GPIO_WritePin(Trigger_Port, Trigger_Pin, GPIO_PIN_RESET);
}

uint8_t UltrasonicReadDistance(void);



