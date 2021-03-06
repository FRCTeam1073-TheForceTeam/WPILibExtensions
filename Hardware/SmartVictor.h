#ifndef SMART_VICTOR_H
#define SMART_VICTOR_H
#include "Victor.h"
#include "Invertable.h"
class SmartVictor : public Victor, public Invertable {
public:
	SmartVictor(int module, int channel, bool isInverted = false);
	void Set(float value);
};
#endif
