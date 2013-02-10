#ifndef STALLABLE_H
#define STALLABLE_H
#define BUFFER 10
#include <stdio.h>
#include <math.h>
class Stallable{
public:
	Stallable();
	void PrintVoltages();
	virtual float StallDetectLimit();	//if recorded data does not oscillate this much in volts we return false.
	bool IsStall();
protected:
	virtual float GetVoltageSource() = 0;
	float priorVoltage, currentVoltage;
	void ProcessVoltageData();
	void ResetData();
};
#endif
