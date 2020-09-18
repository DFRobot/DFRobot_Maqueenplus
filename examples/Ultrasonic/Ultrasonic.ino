/*!
 * @file patrol.ino
 * @brief MaqueenPlus avoid obstacles
 * @n When the distance between MaqueenPlus and obstacle ahead is less than 20cm, MaqueenPlus draws back to avoid it
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
  //Set RGB led color of MaqueenPlus 
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.YELLOW);
}

void loop() {
  //Receive the distance returned by ultrasoinc sensor
  uint8_t distance  = MaqueenPlus.ultraSonic(MaqueenPlus.P0, MaqueenPlus.P1);

  if(distance < 20 && distance != 0){
    MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CCW, 160);
    MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CCW, 50);
    delay(500);
  }else{
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CW, 50);
  }
}