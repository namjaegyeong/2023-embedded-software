#include <Wire.h>
const int PCF8574 = 0x20;               // 슬레이브 주소
int value = 0x01;                       // PCF8574 모듈에 전송할 값 (0x01로 초기화)
void setup() {
    Wire.begin();                       // I2C 통신 시작
}

void loop() {
    WireSend();                         // PCF8574 모듈에 값 전송
    if (value == 0x80) {                // value가 0x80일 때 초기화
        value = 0x01;                   // 0x01부터 다시 시작
    } else {
        value <<= 1;                    // value 값을 왼쪽으로 1 비트 이동
    }
    delay(200);                         // 200ms 딜레이
}

void WireSend() {                  
    Wire.beginTransmission(PCF8574);    // PCF8574 모듈 주소 값을 가진 장치와 통신 시작
    Wire.write(value);                  // PCF8574 모듈에 value 전송
    Wire.endTransmission();             // 통신 종료
}