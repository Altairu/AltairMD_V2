#include "motor.h"

int speed1 = -250;        // 初期値を-250に設定
int speed_increment = 1;  // 速度の増加量を設定
Motor mtr[4];
void setup() {
  Serial.begin(115200);
  mtr[0].init(9, 10, 11);
}

void loop() {  // speed1を増加または減少させます
  speed1 += speed_increment;

  // 速度が255または-255に達した場合、増加方向を反転します
  if (speed1 >= 250 || speed1 <= -250) {
    speed_increment = -speed_increment;
  }

  // モーターを制御
  //speed1=100;
  mtr[0].ugoki(speed1);
  

  
  // 現在のspeed1の値をシリアルモニタに表示
  Serial.print("speed1:");
  Serial.print(speed1);
  Serial.println('\t');
  delay(30);
}
