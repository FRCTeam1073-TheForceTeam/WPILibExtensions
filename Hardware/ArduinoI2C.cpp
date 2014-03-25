#include "ArduinoI2C.h"
ArduinoI2C::ArduinoI2C(int port) {
	interface = DigitalModule::GetInstance(port)->GetI2C(1);
}

void ArduinoI2C::SendData(uint8_t data) {
	uint8_t* msg = new uint8_t[1];
	msg[0] = (uint8_t) data;
	uint8_t* resp = new uint8_t[100];
	interface->Transaction(msg, sizeof(uint8_t), resp, 0);
}

I2C* ArduinoI2C::GetI2CInterface() { return interface; }
