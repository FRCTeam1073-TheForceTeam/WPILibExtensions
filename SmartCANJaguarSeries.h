#ifndef SMART_CAN_JAGUAR_SERIES_H
#define SMART_CAN_JAGUAR_SERIES_H
#include "SmartCANJaguar.h"
#include <vector>
class SmartCANJaguarSeries {
public:
	SmartCANJaguarSeries();
	void Add(SmartCANJaguar* jaguar);
	void Set(float value);
	void Off();
	// just in case you want a specific pointer
	SmartCANJaguar* Get(int index);
private:
	vector<SmartCANJaguar*> jagList;
};

#endif
