#include "lpc17xx_dac.h"             // DAC 관련 함수들을 사용하기 위한 헤더 파일
#include "lpc17xx_uart.h"            // UART 통신을 위한 헤더 파일
#include "lpc17xx_pinsel.h"          // 핀 설정을 위한 헤더 파일
#include "lpc17xx_libcfg_default.h"  // 기본 라이브러리 구성을 위한 헤더 파일
#include "debug_frmwrk.h"            // 디버깅 프레임워크를 위한 헤더 파일

int main(void)
{
      // 구조체 선언 및 변수 초기화
      PINSEL_CFG_Type PinCfg;
      uint32_t time;
      float rate = 0;               // DAC 값을 업데이트할 때 사용될 값을 저장하는 변수
   
      SystemInit();                 // 시스템 관련 설정 초기화
      
      // 핀 설정 구조체 초기화
      PinCfg.Funcnum = 2;           // 핀 기능 번호 설정 (DAC 기능으로)
      PinCfg.OpenDrain = 0;         // 오픈 드레인 모드 비활성화
      PinCfg.Pinmode = 0;           // 풀업/풀다운 저항 설정 없음
      PinCfg.Pinnum = 26;           // 핀 번호 26 설정
      PinCfg.Portnum = 0;           // 포트 0에 있는 핀 설정
      PINSEL_ConfigPin(&PinCfg);    // 위에서 설정한 핀 구성을 적용
      
      // 디버그 인터페이스 초기화
      debug_frmwrk_init();
   
      // DAC 초기화
      DAC_Init(LPC_DAC);            // 내장 DAC를 초기화하는 함수 호출

      // 무한 루프 시작
      while (1)
      {
         // DAC 값을 1부터 0x3FF까지 업데이트
         for(time = 1; time < 0x3FF; time++)
         {   
            // DAC 값 업데이트, time*rate 계산을 통해 출력 값 조절
            DAC_UpdateValue(LPC_DAC, (uint32_t)(time * rate));
         }
         
         // 매 루프마다 rate 값을 조금씩 증가시킴 (0.001씩 증가)
         rate += 0.001;
         
         // rate가 1 이상이 되면 다시 0으로 초기화
         // 이렇게 하면 DAC의 출력은 점점 증가했다가 다시 0으로 떨어지는 패턴을 반복함
         if(rate >= 1)
         {
            rate = 0;
         }
      }
}
