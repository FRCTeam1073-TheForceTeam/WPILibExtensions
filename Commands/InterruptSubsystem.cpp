#include "InterruptSubsystem.h"
InterruptSubsystem::InterruptSubsystem(Subsystem* subsystem) {Requires(subsystem);}
bool InterruptSubsystem::IsFinished() {return true;}
