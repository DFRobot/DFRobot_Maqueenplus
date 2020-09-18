/*!
 * @file DFRobot_MaqueenPlus.h
 * @brief This is a library for MaqueenPlus from DFRobot
 * @n This library can be used to control the corresponding sensors on MaqueenPlus to complete different projects and functions
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence      The MIT License (MIT)
 * @author       [Tang](jie.tang@dfrobot.com)
 * @version      V1.0
 * @eGDAte       2020-09-15
 * @get          from https://www.dfrobot.com
 * @url          https://github.com/DFRobot/DFRobot_MaqueenPlus
 */

#ifndef  DFRobot_MaqueenPlus_H
#define  DFRobot_MaqueenPlus_H

#include <Arduino.h>
#include <Wire.h>

#define ENABLE_DBG
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define DFROBOT_MAQUEEMPLUS_IRPIN    16
#define DFROBOT_MAQUEEMPLUS_LEFT     1
#define DFROBOT_MAQUEEMPLUS_RIGHT    2
#define DFROBOT_MAQUEEMPLUS_L1       1
#define DFROBOT_MAQUEEMPLUS_L2       2
#define DFROBOT_MAQUEEMPLUS_L3       5
#define DFROBOT_MAQUEEMPLUS_R1       3
#define DFROBOT_MAQUEEMPLUS_R2       4
#define DFROBOT_MAQUEEMPLUS_R3       6
#define DFROBOT_MAQUEEMPLUS_S1       1
#define DFROBOT_MAQUEEMPLUS_S2       2

class DFRobot_MaqueenPlus
{
public:
  /**
   * @brief Enable or disable PID
   */
  enum PID{
    OFF = 0,
    ON  = 1
  };
  /**
   * @brief Positionition selection, suitable for RGB LEDs and motor selection
   */
  enum Position{
    LEFT  = 1,
    RIGHT = 2,
    ALL   = 3
  };
  /**
   * @brief Motor direction selection
   */
  enum Dir{
    CW  = 1,
    CCW = 2
  };
  /**
   * @brief line-tracking sensor selection
   */
  enum Patrol{
    L1 = 1,
    L2 = 2,
    L3 = 5,
    R1 = 3,
    R2 = 4,
    R3 = 6
  };
  /**
   * @brief RGB LEDs color selection
   */
  enum Color{
    RED    = 1,
    GREEN  = 2,
    BLUE   = 4,
    YELLOW = 3,
    PINK   = 5,
    CYAN   = 6,
    WHITH  = 7,
    PUT    = 8
  };
  /**
   * @brief Serve port selection
   */
  enum Servo{
    S1 = 1,
    S2 = 2,
    S3 = 3
  };
  /**
   * @brief Ultrasonic pin selection
   */
  enum Pin{
    P0  = 0,
    P1  = 1,
    P2  = 2,
    P8  = 8,
    P12 = 12,
    P13 = 13,
    P14 = 14,
    P15 = 15
  };
  DFRobot_MaqueenPlus(TwoWire *pWire = &Wire, uint8_t address = 0x10)
  {
    _pWire = pWire;
    _address = address;
  };

  /**
   * @brief Init I2C until success 
   */
  uint8_t begin(void);
  /**
   * @brief PID operation control
   * @param state To disable or enable PID
   */
  void PIDSwitch(PID state);
  /**
   * @brief Control the direction and speed of MaqueenPlus
   * @param motor Motor control selection
   * @param direction Motor rotation direction 
   * @param speed Motor speed(range:0~255)
   */
  void motorControl(Position motor, Dir direction, uint8_t speed);
  /**
   * @brief Get wheel speed
   * @param motor Select left or right motor
   * @return Return the speed of the selected motor 
   */
  uint8_t getSpeed(Position motor);
  /**
   * @brief Get rotation direction
   * @param motor Select left or right motor 
   * @return  0: stop 1: forward 2: backward
   */
  uint8_t getDirection(Position motor);
  /**
   * @brief  Get the number of revolutions
   * @param motor Select left or right motor
   * @return Return the revolutions
   */
  float getDistance(Position motor);
  /**
   * @brief Clear the number of revolutions
   * @param motor Select left or right motor
   */
  void clearDistance(Position motor);
  /**
   * @brief  Get line-tracking sensor status
   * @param senser Select line-tracking sensor 
   * @return Returns the status of line-tracking sensor
   */
  uint8_t getPatrol(Patrol senser);
  /**
   * @brief Get grayscale value of line-tracking sensor
   * @param senser Select line-tracking sensor 
   * @return  Return the grayscale value of line-tracking sensor
   */
  uint16_t getGrayscale(Patrol senser);
  /**
   * @brief Set the RGB led color
   * @param colour Select Color
   */
  void setRGB(Position light,Color color);
  /**
   * @brief Servo control
   * @param servo Select servo
   * @param angle Control servo angle(range:0°~180°)
   */
  void servoControl(Servo servo, uint8_t angle);
  /**
   * @brief Get ultrasonic distance
   * @param trig   TRIG Pin
   * @param echo   ECHO Pin
   * @return  Return ultrasonic distance information
   */
  uint8_t ultraSonic(Pin trig, Pin echo);
  /**
   * @brief Get infrared data
   * @return  Return infrared key information
   */
 uint32_t getIR(void);
  /**
   * @brief  Get version information
   * @return  Return version information
   */
  String getVersion(void); 
private:
  uint8_t _echoPin;
  uint8_t _trlgPin;
  TwoWire *_pWire;
  uint8_t _address;
  uint16_t _pulseWidth = 0;
  uint16_t _irCode = 0x00;
  uint32_t _duration;
  /**
   * @brief  Get level change time
   */
  uint64_t myPulseIn(uint32_t pin, uint32_t value, long maxDuration = 100000);
  /**
   * @brief   Write register value through IIC bus
   * @param reg  Register address 8bits
   * @param pBuf Storage cache to write data in
   * @param size The length of data to be written
   */
  void writeReg(uint8_t reg, void *pBuf, size_t size);
  /**
   *@brief Read register value through IIC bus
   * @param reg  Register address 8bits
   * @param pBuf Read data storage cache
   * @param size Read the length of data
   * @return Return the read length, 0 indicates it failed to read 
   */
  uint8_t readReg(uint8_t reg, void *pBuf, size_t size);

};
#endif