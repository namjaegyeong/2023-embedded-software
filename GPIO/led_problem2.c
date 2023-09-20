#include "lpc17xx_gpio.h"

/*
 * 스위치 (P2.10) ON => 8개의 LED ON
 * 스위치 (P2.10) OFF => 8개의 LED OFF 동작하는 프로그램
 */

void Delay(long d_t)
{
	long k;
	for(k=0; k<=d_t; k++);
}

int main (void) 
{
	uint32_t sw = 0;
	SystemInit();

	GPIO_SetDir(1, 0xB0000000, 1);         
	GPIO_SetDir(2, 0x0000007C, 1);         
	GPIO_SetDir(2, 0x00000400, 0);			

	GPIO_ClearValue(1, 0xB0000000);
	GPIO_ClearValue(2, 0x0000047C);

 	while(1)
	{
		//TODO				
	}
}