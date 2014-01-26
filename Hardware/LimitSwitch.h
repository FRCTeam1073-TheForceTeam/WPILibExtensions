#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H
#include "WPILib.h"
#define PULL_UP_RESISTOR 0
inline bool LimitPressed(DigitalInput* input) {return input->Get() == PULL_UP_RESISTOR;}
inline bool LimitPressed(int input){return input == PULL_UP_RESISTOR;}
#endif
