#include "InterruptCallsEndCommand.h"
InterruptCallsEndCommand::InterruptCallsEndCommand() : Command() {}
void InterruptCallsEndCommand::Interrupted() { End(); }
