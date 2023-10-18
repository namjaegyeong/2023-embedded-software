#include "lpc17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_libcfg_default.h"   
#include "lpc17xx_pinsel.h"

uint8_t led;

void Delay(long d_t)
{
    long k;
    for (k=0; k<d_t; k++);
}

void EINT0_IRQHandler(void)
{                   
    LPC_SC->EXTINT = 0x01;       
    GPIO_ClearValue(2,0x0000007C);
    led = led << 1 ;
}

int main(void)
{
    /* 인터럽트 파라미터 초기화 */
    PINSEL_CFG_Type PinCfg;         //Import PINSEL_CFG structure
    led = 0x04;

    SystemInit();                   //System initialization
    GPIO_SetDir(1, 0xB0000000, 1);  //Set GPIO pins 28,29,31 of Port1 as output    
    GPIO_SetDir(2, 0x0000007C, 1);  //Set GPIO pins 2,3,4,5,6 of Port2 as output    

    GPIO_ClearValue(1, 0xB0000000); //Turn off GPIO pins 28,29,31 of Port1 : LED 1,2,3 off
    GPIO_ClearValue(2, 0x0000007C); //Turn off GPIO pins 2,3,4,5,6 of Port2 : LED 4,5,6,7,8 off

    /* EINT를 쓰기 위해서 EXTINT, EXTMODE, EXTPOLAR의 값을 0으로 초기화 */
    LPC_SC->EXTINT = 0x0;
    LPC_SC->EXTMODE = 0x0;
    LPC_SC->EXTPOLAR = 0x0;     
                
    LPC_SC->EXTMODE = 0x1;          // 에지 트리거 인터럽트 설정   
    LPC_SC->EXTPOLAR = 0x0;         // 하강 에지 트리거 인터럽트 설정  

    /* 포트2의 10번핀을 EINT0로 동작하도록 아래처럼 설정 */
    PinCfg.Funcnum = 1;             // 포트 2의 10번 EINT0 동작 설정
    PinCfg.OpenDrain = 0;           // 오픈드레인 사용하지 않음
    PinCfg.Pinmode = 0;             // Pull-Up으로 설정 Pull-Up(0), Tri-State(2), Pull-Down(3) 
    PinCfg.Pinnum = 10;             // 10핀 설정
    PinCfg.Portnum = 2;             // 포트 2 설정
    
    PINSEL_ConfigPin(&PinCfg);      //EINT0 동작 설정

    NVIC_EnableIRQ(EINT0_IRQn);     // EINT0 활성화
   
   while(1){
    GPIO_SetValue(2,led);
    Delay(10000);
    if (led > 0x70)
        led = 0x04;
   }
}