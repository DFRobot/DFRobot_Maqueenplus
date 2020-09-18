/*!
 * @file patrol.ino
 * @brief Control servo via the servo port on MaqueenPlus 
 * @n Servo connected to port S1 of MaqueenPlus rotates from 0 to 180 degrees, and then back to 0.
 *     
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence      The MIT License (MIT)
 * @author       [Tang](jie.tang@dfrobot.com)
 * @version      V1.0
 * @date         2020-09-15
 * @get         from https://www.dfrobot.com
 * @url         https://github.com/DFRobot/DFRobot_MaqueenPlus
 */

#include <DFRobot_MaqueenPlus.h>

DFRobot_MaqueenPlus  MaqueenPlus;

void setup() { 
  //初始化串口打印 Initialize serial printing
  Serial.begin(9600);
  //Init I2C until success
  while(MaqueenPlus.begin() != 0){
    Serial.println("I2C initialization failed");
  }
  Serial.println("I2C initialization success");
  //设置麦昆Plus的RGB灯颜色 Set the RGB light color of the MaQueen Plus
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.YELLOW);
}

void loop() {
  for(uint8_t i=0; i<180; i++){
    MaqueenPlus.servoControl(MaqueenPlus.S1, i);
    delay(100);
  }
  for(uint8_t i=180; i>0; i--){
    MaqueenPlus.servoControl(MaqueenPlus.S1, i);
    delay(100);
  }
}