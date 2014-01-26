#ifndef SMART_CAN_JAGUAR_SERIES_H
#define SMART_CAN_JAGUAR_SERIES_H
#include "SmartCANJaguar.h"
#include "SpeedControllerSeries.h"
#include <vector>
#include <cstdarg>
class SmartCANJaguarSeries : public SpeedControllerSeries{
public:
	SmartCANJaguarSeries();
	void Add(SmartCANJaguar* jaguar);
	void Add(int count, ...);
	void ConfigureVoltageMode();
	void ConfigureSpeedMode();
	// just in case you want a specific pointer
	SmartCANJaguar* Get(int index);
private:
	SpeedControllerSeries::Add;
};

#endif
