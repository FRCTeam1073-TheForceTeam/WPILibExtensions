#ifndef SPEED_CONTROLLER_SERIES_H
#define SPEED_CONTROLLER_SERIES_H
#include "WPILib.h"
#include <vector>
#include <cstdarg>
class SpeedControllerSeries {
public:
	SpeedControllerSeries();
	virtual void Add(SpeedController* speedController);
	virtual void Add(int count, ...);
	void Set(float value);
	void Off();
	// just in case you want a specific pointer
	SpeedController* Get(int index);
protected:
	vector<SpeedController*>* speedControllerList;
};
#endif
