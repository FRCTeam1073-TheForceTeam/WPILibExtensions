#ifndef STALLABLE_H
#define STALLABLE_H
#define BUFFER 10
#include <stdio.h>
#include <math.h>
class Stallable{
public:
	Stallable();
	void PrintVoltages();
	virtual float StallDetectLimit();	//if recorded data does not oscilate this much in volts we return false.
	bool IsStall();
protected:
	virtual float GetVoltageSource() = 0;
	float* voltages;
	void FillStallArray();
	void ResetArray();
private:
	int index;
	bool hasArrayInit;
};
#endif
