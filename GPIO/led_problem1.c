#include "lpc17xx_gpio.h"

/*
 * D13->D14->D15->D16->D17->D18->D19->D20
 * D20->D19->D18->D17->D16->D15->D14->D13
 * 순서로 점등되는 LED가 변경되는 동작을 반복하는 프로그램
 */

#define LED_NUM     8

void Delay(long d_t)
{
	long k;
	for(k=0; k<=d_t; k++);
}

int main (void) 
{
	int num = -1;
	int dir =  1;

	SystemInit();

	GPIO_SetDir(1, 0xB0000000, 1); 
	GPIO_SetDir(2, 0x0000007C, 1);          

	GPIO_ClearValue(1, 0xB0000000);
	GPIO_ClearValue(2, 0x0000007C);

	while(1)
	{
		//TODO
	}
}