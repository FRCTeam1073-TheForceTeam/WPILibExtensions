#include "SaitekX52Throttle.h"
SaitekX52Throttle::SaitekX52Throttle(int port) : SmartJoystick(port) {this->ToggleInvertZAxis();}

float SaitekX52Throttle::GetSaitekThrottleControl() {return SmartJoystick::GetZ();}

int SaitekX52Throttle::GetEButtonNumber() { return 8; }
int SaitekX52Throttle::GetIButtonNumber() { return 30; }
int SaitekX52Throttle::GetFunctionButtonNumber() {return 27;}
int SaitekX52Throttle::GetStartStopButtonNumber() {return 28;}
int SaitekX52Throttle::GetResetButtonNumber() {return 29;}

bool SaitekX52Throttle::GetEButton() {return GetRawButton(GetEButtonNumber()); }
bool SaitekX52Throttle::GetIButton() { return GetRawButton(GetIButtonNumber());}
bool SaitekX52Throttle::GetFunctionButton() { return GetRawButton(GetFunctionButtonNumber()); }
bool SaitekX52Throttle::GetStartStopButton() {return GetRawButton(GetStartStopButtonNumber());}
bool SaitekX52Throttle::GetResetButton() { return GetRawButton(GetResetButtonNumber()); } 
