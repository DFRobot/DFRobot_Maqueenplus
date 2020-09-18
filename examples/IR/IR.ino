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
  //接收红外遥控键值 Receive infrared remote control key value
  uint8_t irData = MaqueenPlus.getIR();

  if(irData == 21){//前进 Forward
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CW, 100);
  }else if(irData == 29){//后退 Back
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CCW, 100);
  }else if(irData == 24){//左转  Turn left
    MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 0);
    MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 200);
  }else if(irData == 26){//右转 Ture right
    MaqueenPlus.motorControl(MaqueenPlus.LEFT, MaqueenPlus.CW, 200);
    MaqueenPlus.motorControl(MaqueenPlus.RIGHT, MaqueenPlus.CW, 0);
  }else if(irData == 25){//停止 Stop
    MaqueenPlus.motorControl(MaqueenPlus.ALL, MaqueenPlus.CCW, 0);
  }
}
