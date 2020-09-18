/*!
 * @file patrol.ino
 * @brief Get the returned data of MaqueenPlus 
 * @n Serial port print the returned data of MaqueenPlus 
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
  MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CW, 100);
}

void loop() {
  Serial.println("--------------------");
  Serial.print("Version:");
  Serial.println(MaqueenPlus.getVersion());
  Serial.println("--------------------");
  Serial.print("Speed_L:");
  Serial.println(MaqueenPlus.getSpeed(MaqueenPlus.LEFT));
  Serial.print("Speed_R:");
  Serial.println(MaqueenPlus.getSpeed(MaqueenPlus.RIGHT));
  Serial.println("--------------------");
  Serial.print("Direction_L:");
  Serial.println(MaqueenPlus.getDirection(MaqueenPlus.LEFT));
  Serial.print("Direction_R:");
  Serial.println(MaqueenPlus.getDirection(MaqueenPlus.RIGHT));
  Serial.println("--------------------");
  Serial.print("Distance_L:");
  Serial.println(MaqueenPlus.getDistance(MaqueenPlus.LEFT));
  Serial.print("Distance_R:");
  Serial.println(MaqueenPlus.getDistance(MaqueenPlus.RIGHT));
  Serial.println("--------------------");
  Serial.print("Grayscale_L1:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.L1));
  Serial.print("Grayscale_L2:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.L2));
  Serial.print("Grayscale_L3:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.L3));
  Serial.print("Grayscale_R1:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.R1));
  Serial.print("Grayscale_R2:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.R2));
  Serial.print("Grayscale_R3:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.R3));
  if(MaqueenPlus.getDistance(MaqueenPlus.LEFT) >= 20 || MaqueenPlus.getDistance(MaqueenPlus.RIGHT) >= 20){
    //清除全部轮胎圈数 clear the revolutions of wheel
    MaqueenPlus.clearDistance(MaqueenPlus.ALL);
  }
  delay(1000);
}
