#ifndef SMART_TALON_H
#define SMART_TALON_H
#include "WPILib.h"
#include "Invertable.h"
class SmartTalon : public Talon, public Invertable {
public:
	SmartTalon(int module, int channel);
	void Set(float value);
};
#endif
