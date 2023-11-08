#include "lpc17xx_dac.h"                 // DAC 관련 기능을 포함하기 위한 헤더 파일
#include "lpc17xx_uart.h"                // UART 관련 기능을 포함하기 위한 헤더 파일
#include "lpc17xx_pinsel.h"              // 핀 설정 관련 기능을 포함하기 위한 헤더 파일
#include "lpc17xx_libcfg_default.h"      // 기본 라이브러리 설정을 포함하기 위한 헤더 파일
#include "debug_frmwrk.h"                // 디버그 프레임워크를 포함하기 위한 헤더 파일
#include "lpc17xx_timer.h"               // 타이머 관련 기능을 포함하기 위한 헤더 파일
#include "lpc17xx_clkpwr.h"              // 클록 및 전력 관련 기능을 포함하기 위한 헤더 파일

uint8_t g_ulFlags = 0;                   // 글로벌 플래그 변수 (인터럽트 핸들러와 메인 루프에서 사용)

TIM_TIMERCFG_Type TIM_ConfigStruct;      // 타이머 설정을 위한 구조체
TIM_MATCHCFG_Type TIM_MatchConfigStruct; // 타이머 일치 설정을 위한 구조체

// 타이머 인터럽트 핸들러 함수
void TIMER0_IRQHandler(void)
{
   TIM_ClearIntPending(LPC_TIM0,0);      //Timer0 인터럽트 클리어
   // Todo
   // 타이머 인터럽트가 발생할 때 동작을 작성합니다.
   // 시간이 지날 수록 DAC의 출력 전압을 점차 증가해야 합니다.
}

int main(void)
{
    PINSEL_CFG_Type PinCfg;              // 핀 설정을 위한 구조체
    uint32_t time;                       // 시간 변수
    float rate = 1;                      // DAC 값 조정을 위한 비율

    SystemInit();                        // 시스템 초기화 함수 호출

    // 핀 설정 구조체 초기화
    PinCfg.Funcnum = 2;                  // 기능 번호 설정 (핀 기능 선택)
    PinCfg.OpenDrain = 0;                // 오픈 드레인 모드 비활성화
    PinCfg.Pinmode = 0;                  // 핀 모드 설정
    PinCfg.Pinnum = 26;                  // 핀 번호 설정 (P0.26)
    PinCfg.Portnum = 0;                  // 포트 번호 설정 (포트 0)
    PINSEL_ConfigPin(&PinCfg);           // 핀 설정 적용

    DAC_Init(LPC_DAC);                   // DAC 초기화

    TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL;          //마이크로 초 단위로 타이머 clock을 환산
    TIM_ConfigStruct.PrescaleValue = 100;                          //1 clock 당 카운트 시간은 100㎲ 설정

    TIM_MatchConfigStruct.MatchChannel = 0;                        //타이머0을 사용하도록 설정
    TIM_MatchConfigStruct.IntOnMatch = ENABLE;                     //타이머 일치 동작시 인터럽트가 발생
    TIM_MatchConfigStruct.ResetOnMatch = ENABLE;                   //타이머 일치 동작시 타이머의 값을 리셋
    TIM_MatchConfigStruct.StopOnMatch = DISABLE;                   //타이머 일치 동작을 주기적으로 발생
    TIM_MatchConfigStruct.ExtMatchOutputType=TIM_EXTMATCH_NOTHING; //타이머의 외부 출력핀은 사용하지 않음
    TIM_MatchConfigStruct.MatchValue = 5000;                       //0.5초 간격으로 타이머 일치 동작이 발생 5000 * 100㎲ = 500ms

    // 타이머 초기화 및 설정 적용
    TIM_Init(LPC_TIM0, TIM_TIMER_MODE,&TIM_ConfigStruct);          //타이머/카운터 장치를 초기화 한다.
    TIM_ConfigMatch(LPC_TIM0,&TIM_MatchConfigStruct);              //타이머 일치 동작을 설정한다.

    NVIC_EnableIRQ(TIMER0_IRQn);                                   //TIMER0_IRQn 인터럽트 활성화
    TIM_Cmd(LPC_TIM0,ENABLE);                                      //TIM0 동작        
      
    while (1)
    {
        // Todo
        // g_ulFlags 값에 따라 다른 DAC 값 범위를 업데이트하는 코드를 작성합니다.
        // DAC의 출력 전압을 점차 증가해야 합니다.
        // 예를 들어, g_ulFlags가 1일 때는 0x0FF까지, 2일 때는 0x1FF까지 증가하게 작성해야 합니다.
    }
}