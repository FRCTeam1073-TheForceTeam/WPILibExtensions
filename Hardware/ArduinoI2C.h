#ifndef ARDUINO_I2C_H
#define ARDUINO_I2C_H
#include "I2C.h"
#include "WPILib.h"
class ArduinoI2C {
public:
	ArduinoI2C(int port);
	void SendData(uint8_t data);
	I2C* GetI2CInterface();
private:
	I2C* interface;
};
#endif
