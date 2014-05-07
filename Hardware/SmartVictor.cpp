#include "SmartVictor.h"
SmartVictor::SmartVictor(int module, int channel, bool isInverted)
 : Victor(module, channel), Invertable(isInverted)
 {
 	// ...
 }

 void SmartVictor::Set(float value) {
 	if (IsInverted())
 		value *= -1;
 	Victor::Set(value);
 }
