#ifndef STALLABLE_H
#define STALLABLE_H
#define BUFFER 10
#include <stdio.h>
#include <math.h>

#define VOLT_HISTORY_LEN 3

class Stallable{
public:
	Stallable();
	void PrintVoltages();
	virtual float StallDetectLimit();	//if recorded data does not oscillate this much in volts we return false.
	bool IsStall();
protected:
	virtual float GetVoltageSource() = 0;
	float voltageHistArray[VOLT_HISTORY_LEN];
	void ProcessVoltageData();
	void ResetData();
private:
	static const float stallDetectLimitVal = 0.3f;
};
#endif
