# DFRobot_WiFi_IoT_Module

Maqueen plus is a STEM educational robot . Optimized with better power management and larger capacity power supply, it can be perfectly compatible with Huskylens AI Vision Sensor.
   
## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

 
## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  /**
   * @brief Enable or disable PID
   */
  enum PID{
    OFF = 0,
    ON  = 1
  };
  /**
   * @brief Position selection, suitable for RGB LEDs and motor selection
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
  void motorControl(POS motor, Dir direction, uint8_t speed);
  /**
   * @brief Get wheel speed
   * @param motor Select left or right motor
   * @return Return the speed of the selected motor 
   */
  uint8_t getSpeed(POS motor);
  /**
   * @brief Get rotation direction
   * @param motor Select left or right motor 
   * @return  0: stop 1: forward 2: backward
   */
  uint8_t getDirection(POS motor);
  /**
   * @brief  Get the number of revolutions
   * @param motor Select left or right motor
   * @return Return the revolutions
   */
  float getDistance(POS motor);
  /**
   * @brief Clear the number of revolutions
   * @param motor Select left or right motor
   */
  void clearDistance(POS motor);
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
  void setRGB(POS light,Colour colour);
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
 uint8_t getIR(void);
  /**
   * @brief  Get version information
   * @return  Return version information
   */
  String getVersion(void); 
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
micro:bit          |      √       |              |             | 



## History

- Data 2020-09-15
- Version V1.0


## Credits

Written by Tang(jie.tang@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))





