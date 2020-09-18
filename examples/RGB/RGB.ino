/*!
 * @file patrol.ino
 * @brief MaqueenPlus RGB LEDs light up in different colors
 * @n MaqueenPlus RGB LEDs light up in differernt colors repeatedly
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
  //Initi serial print
  Serial.begin(9600);
  //Init I2C until success
  while(MaqueenPlus.begin() != 0){
    Serial.println("I2C initialization failed");
  }
  Serial.println("I2C initialization success");
}

void loop() {
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.RED);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.GREEN);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.BLUE);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.YELLOW);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.PINK);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.CYAN);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.WHITH);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.PUT);
  delay(100);
}