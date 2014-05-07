#include "SmartVictor.cpp"
SmartVictor::SmartVictor(int module, int channel)
 : Victor(module, channel), Invertable(IsInverted)
 {
 	// ...
 }

 void SmartVictor::Set(float value) {
 	if (IsInverted())
 		value *= -1;
 	Victor::Set(value);
 }
