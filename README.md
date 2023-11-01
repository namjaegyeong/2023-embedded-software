# How to set up a Keil

### 파일 설치 

  1. LPC1768 드라이버 다운로드 https://drive.google.com/file/d/1qdtXqvLqQoIKSMrtabgRIH5fCs94qsPv/view
  2. Keil 다운로드 https://drive.google.com/file/d/1tqcS9Xxc6cbtUSx8kFb53YsP7FvQ000n/view?usp=sharing 

### 1, Pack Installer => 
* 왼쪽 Devices 탭 -> LPC1768 선택 
* 오른쪽 packs 탭 -> Keil:LPC1700_DFP install

![케일설치_1](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/cea0514c-3ccf-4c8b-9082-858620548051)

### 2, New MuVision Project... => 
* Select Device for Target 'Target 1' ... =>
* NXP -> LPC1768 선택

![케일설치_2](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/efc39e39-7bb7-4647-8318-a1fb923e4403)
![KakaoTalk_20231101_175223420](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/92912906-6fa6-4c49-a20b-69ae3730601e)
![케일설치_3](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/8578516f-107c-4ab2-abc5-7b232fd57ac6)

### 3, Manager Run-Time Environment =>
* CMSIS -> CORE 선택
* Device -> Startup 선택 후 OK

![케일설치_4](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/184ef74e-4365-40ca-a3b2-18d9ab3889ed)

### 4, Target1 폴더 오른쪽 버튼 클릭 =>  
* Options for Target 1... (마법봉) 선택 => 
* Target 탭 -> Arm Complier -> Muvision 현재 버전으로 선택
* C/C++ 탭 -> Include path -> LPC1768 드라이버 안에 있는 include 폴더 선택 (..\lpc175x_6x_cmsis_driver_library_0\lpc175x_6x_cmsis_driver_library\Drivers\include)

![케일설치_4 5](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/14d9525f-af47-4102-99e3-149de437b989)
![케일설치_5](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/1bd1e961-b8f3-4b80-84d4-1cdd421df677)
![케일설치_5 5](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/0279a468-bac8-4fbb-88e0-f552bf0a6596)

### 5, Target1 폴더 오른쪽 버튼 클릭 =>  
* Manage Project Items.... =>
* Add Files 클릭 -> lpc17xx_gpio.c 파일 추가 (..\lpc175x_6x_cmsis_driver_library_0\lpc175x_6x_cmsis_driver_library\Drivers\source)

![케일설치_5 8](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/74dcd2c6-44b4-4728-91ae-b1588faf4974)
![케일설치_6](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/f5d86fa7-f8aa-46ff-bdf8-0094f87175ef)

### 6, Source Group 1 폴더 오른쪽 버튼 클릭 => 
* Add New Item to Group ‘Source Group 1’... =>
* main.c 파일 추가

![케일설치_7](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/ec8a544e-ec69-4ed1-938e-3785cdb8e033)
![케일설치_8](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/b1396b96-a8ec-41e7-9c02-7dcd71775af8)

### 7, 코드 작성 =>
* main.c 파일에 코드 작성

![코드추가](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/ce7f1ae5-c0ca-4e6d-8b3c-26b091b7cbeb)

### 8, Target1 폴더 오른쪽 버튼 클릭 =>
* build target => load 

![케일설치_9](https://github.com/namjaegyeong/2023-embedded-software/assets/57249939/c5940f8a-5b37-463a-b691-23a9b4baadc4)

# 참고
* https://www.electronicshub.org/setting-up-keil-mdk-for-lpc1768/
* https://www.youtube.com/watch?v=5KBiw-anwrQ
