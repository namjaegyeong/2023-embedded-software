# How to set up a Keil

### 파일 설치 

  1. LPC1768 드라이버 다운로드 https://drive.google.com/file/d/1qdtXqvLqQoIKSMrtabgRIH5fCs94qsPv/view
  2. Keil 다운로드 https://drive.google.com/file/d/1tqcS9Xxc6cbtUSx8kFb53YsP7FvQ000n/view?usp=sharing 

### 1, package installer => 
* 왼쪽 Devices 탭 -> LPC1768 선택 
* 오른쪽 packs 탭 -> Keil:LPC1700_DFP install

### 2, 새로운 프로젝트 생성 => 
* Select Device for Target 'Target 1' ... =>
* NXP -> LPC1768 선택

### 3, Manager Run-Time Environment =>
* CMSIS -> CORE 선택
* Device -> Startup 선택 후 OK

### 4,  Options for Target(마법봉) 선택 => 
* Target 탭 -> Arm Complier -> Muvision 현재 버전으로 선택
* C/C++ 탭 -> Include path -> LPC1768 드라이버 안에 있는 include 폴더 선택 (..\lpc175x_6x_cmsis_driver_library_0\lpc175x_6x_cmsis_driver_library\Drivers\include)

### 5, Target1 폴더 오른쪽 버튼 클릭 =>  
* Manage Project Items =>
* Add Files 클릭 -> lpc17xx_gpio.c 파일 추가 (..\lpc175x_6x_cmsis_driver_library_0\lpc175x_6x_cmsis_driver_library\Drivers\source)

### 6, Source Group 1 폴더 오른쪽 버튼 클릭 => 
* Add New Item to Group ‘Source Group 1’ =>
* main.c 파일 추가 후 코드 작성

### 7, Target1 폴더에 대해 build target => load 

### 참고
* https://www.electronicshub.org/setting-up-keil-mdk-for-lpc1768/
* https://www.youtube.com/watch?v=5KBiw-anwrQ
