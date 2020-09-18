/*!
 * @file patrol.ino
 * @brief Complete the line-tracking using the MaqueenPlus line-tracking sensor 
 * @n Maqueen Plus follows the black lines on the map
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
  if(MaqueenPlus.getPatrol(MaqueenPlus.L2) == 0 &&  MaqueenPlus.getPatrol(MaqueenPlus.L1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.R1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.R2) == 0){
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CW, 50); 
  }else{
    if(MaqueenPlus.getPatrol(MaqueenPlus.L2) == 0 &&  MaqueenPlus.getPatrol(MaqueenPlus.L1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.R1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.R2) == 1){
      MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 160);
      MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 50);
    }else if(MaqueenPlus.getPatrol(MaqueenPlus.L2) == 0 &&  MaqueenPlus.getPatrol(MaqueenPlus.L1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.R1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.R2) == 1){
      MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 200);
      MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 50);
    }if(MaqueenPlus.getPatrol(MaqueenPlus.L2) == 1 &&  MaqueenPlus.getPatrol(MaqueenPlus.L1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.R1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.R2) == 0){
      MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 50);
      MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 160);
    }else if(MaqueenPlus.getPatrol(MaqueenPlus.L2) == 1 &&  MaqueenPlus.getPatrol(MaqueenPlus.L1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.R1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.R2) == 0){
      MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 50);
      MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 200);
    }
  }
}