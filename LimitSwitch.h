#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H
#include "WPILib.h"
inline bool LimitPressed(DigitalInput* input) {return input->Get() == 0;}
#endif
