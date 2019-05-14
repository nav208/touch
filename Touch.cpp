/*
  AT42QT1070 
  Created by Jan Navrátil
  info@suprweb.cz
  2018-10-15

*/

//#include <Wire.h>
#include "Touch.h"

Touch::Touch () {}

void Touch::begin(void){	
		Wire.begin();  		
}

// read register
char Touch::readReg(unsigned char addr_reg)
{
    char result;

    Wire.beginTransmission(ADDR_QTOUCH);
    Wire.write(addr_reg); // register to read
    Wire.endTransmission();
    Wire.requestFrom(ADDR_QTOUCH, 1); // read a byte
    while(Wire.available()) 
    {
        result = Wire.read();
    }
    return result;
}

// write data to register 
void Touch::writeReg(unsigned char addr_reg, unsigned char dta)      // write register
{
    Wire.beginTransmission(ADDR_QTOUCH);
    Wire.write(addr_reg); // register to read
    Wire.write(dta);
    Wire.endTransmission();
}

void Touch::setNTHRForKey(char nthr,char pin)
{
  writeReg(QTOUCH_REG_NTHRK0+pin,nthr);
}
int Touch::getSignalForKey(char pin)
{
  return((readReg(QTOUCH_REG_SIGMSBK0+pin)<<8)+readReg(QTOUCH_REG_SIGLSBK0+pin));
}
int Touch::getRefDataForKey(char pin)
{
  return((readReg(QTOUCH_REG_REFMSBK0+pin)<<8)+readReg(QTOUCH_REG_REFLSBK0+pin));
}
void Touch::setLowPowerMode(int val)                       // set low power mode
{
    writeReg(QTOUCH_REG_LPMODE, val);
}

void Touch::reset()                                        // reset
{
    writeReg(QTOUCH_REG_RESET, 0x55);               // write a non-zero value to reset 
}

void Touch::setMaxDuration(char val)                        // set maxim duration
{
    writeReg(QTOUCH_REG_MAXDURA, val);
}

void Touch::calibrate()                                    // calibrate
{
    writeReg(QTOUCH_REG_CALIBRATE, 0x55);               // write a non-zero value to re-calibrate the device
}



