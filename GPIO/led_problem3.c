#include "lpc17xx_gpio.h"

#define LED_NUM     8

// LED 연결 핀에 대한 마스크 배열
const unsigned long led_mask[] = { 1<<28, 1<<29, 1UL<<31, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6 };

void Delay(unsigned long d_t)
{
  long k;
	for(k=0; k<=d_t; k++);

}

int main(void) 
{
    int num = 0; // 현재 LED의 인덱스
    int state = 0;
    uint32_t sw = 0;

    SystemInit();

    // LED 관련 포트 설정
    GPIO_SetDir(1, 0xB0000000, 1); 
    GPIO_SetDir(2, 0x0000007C, 1);    
    GPIO_SetDir(2, 0x00000400, 0);	      

    // LED 초기 상태: 모든 LED는 꺼진 상태
    GPIO_ClearValue(1, 0xB0000000);
    GPIO_ClearValue(2, 0x0000007C);

    while(1)
    {
        // LED 번호(num)가 LED_NUM보다 크거나 같으면 0으로 초기화하여 처음부터 다시 시작하십시오.
        // 각 LED를 켜고 끄는 사이에 딜레이를 주기 위해 Delay(5000000) 함수를 사용하십시오.
        sw = (GPIO_ReadValue(2) & 0x00000400);
        if(sw == 0x00000000 && state == 0) {
					state = 1;
          if(num < 3) {
            GPIO_SetValue(1, led_mask[num]);
            Delay(5000000);                         
            GPIO_ClearValue(1, led_mask[num]); 
          } else if(num < LED_NUM) {
            GPIO_SetValue(2, led_mask[num]);
            Delay(5000000);                         
            GPIO_ClearValue(2, led_mask[num]);
          } 
					num = (num + 1) % LED_NUM;
        } else if(sw != 0x00000000 && state == 1) {
          state = 0;
        }	
    }
}