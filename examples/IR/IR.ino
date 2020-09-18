/*!
 * @file patrol.ino
 * @brief Control MaqueenPlus by IR
 * @n Control the MaqueenPlus's movement by IR
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
#define IR_UP      127
#define IR_DOWN    111
#define IR_LEFT    223
#define IR_RIGHT   159 
#define IR_STOP    95

DFRobot_MaqueenPlus  MaqueenPlus;

void setup() {
  //Init serial print
  Serial.begin(9600);
  //Init I2C until success
  while(MaqueenPlus.begin() != 0){
    Serial.println("I2C initialization failed");
  }
  Serial.println("I2C initialization success");
  //Set RGB light color of MaqueenPlus
  MaqueenPlus.setRGB(MaqueenPlus.ALL, MaqueenPlus.YELLOW);
}

void loop() {
  // Receive infrared remote controller key value
  uint8_t irData = MaqueenPlus.getIR();
  Serial.println(irData);
  if(irData == IR_UP){//Forward
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CW, 100);
  }else if(irData == IR_DOWN){//Backward
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CCW, 100);
  }else if(irData == IR_LEFT){//Turn left
    MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 0);
    MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 200);
  }else if(irData == IR_RIGHT){//Ture right
    MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 200);
    MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 0);
  }else if(irData == IR_STOP){//Stop
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CCW, 0);
  }
}
