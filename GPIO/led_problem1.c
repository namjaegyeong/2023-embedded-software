#include "lpc17xx_gpio.h"

/*
 * D13->D14->D15->D16->D17->D18->D19->D20
 * D20->D19->D18->D17->D16->D15->D14->D13
 * 순서로 점등되는 LED가 변경되는 동작을 반복하는 프로그램
 */

#define LED_NUM     8

const unsigned long led_mask[] = { 1<<28, 1<<29, 1UL<<31, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6 };

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
   		num += dir;
		if(num == LED_NUM) 
		{ 
			dir = -1; 
			num =  LED_NUM-1; 
		}
		else if(num < 0) 
		{ 	dir =  1; 
			num =  0;
		}
 	    if (num < 3){
			GPIO_SetValue(1, led_mask[num]);
			Delay(500000);                         
			GPIO_ClearValue(1, led_mask[num]);
			Delay(500000);                         
    	}
    	else {
			GPIO_SetValue(2, led_mask[num]);
			Delay(500000);                         
			GPIO_ClearValue(2, led_mask[num]);
			Delay(500000);                         
		}
	}
}