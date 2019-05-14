/*
  AT42QT1070 
  Created by Jan Navrátil
  info@suprweb.cz
  2018-10-15

*/

#ifndef Touch_h
#define Touch_h

#include <Wire.h>

#define ADDR_QTOUCH             0x1B            // address of QTouch
#define QTOUCH_REG_CHIPID       0x00            // read chip id
#define QTOUCH_REG_VERSION      0x01            // Firmware Version
#define QTOUCH_REG_DETSTATUS    0X02            // detection status
#define QTOUCH_REG_KEYSTATUS    0X03            // key status

#define QTOUCH_REG_SIGMSBK0      0X04            // MSByte of KEY0
#define QTOUCH_REG_SIGLSBK0      0X05            // LSByte of KEY0

#define QTOUCH_REG_REFMSBK0      18
#define QTOUCH_REG_REFLSBK0      19

#define QTOUCH_REG_NTHRK0       32
#define QTOUCH_REG_AVEASK0      39
#define QTOUCH_REG_DIK0         46

#define QTOUCH_REG_LPMODE       0X54            // low power mode
#define QTOUCH_REG_MAXDURA      0X55            // max on duration
#define QTOUCH_REG_CALIBRATE    0X56            // calibrate
#define QTOUCH_REG_RESET        0X57            // reset

class Touch {
   
public:

  Touch();

  void begin();
  void setNTHRForKey(char nthr,char pin);
  int getSignalForKey(char pin);
  int getRefDataForKey(char pin);
  void setLowPowerMode(int val);
  void reset();
  void setMaxDuration(char val);
  void calibrate();                                      
  char readReg(unsigned char addr_reg);
  void writeReg(unsigned char addr_reg, unsigned char dta);
  
  	
private:
  
};

#endif
