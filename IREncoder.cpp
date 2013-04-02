#include "IREncoder.h"

//C style function forinterrupt...
void IRInterrupt(uint32_t mask, void *param)
{
	IREncoder* irencoder = (IREncoder*)param;
	irencoder->ProcessInterrupt();
}

IREncoder::IREncoder(UINT32 channel) : DigitalInput(channel)
{
	SetupInterrupts();
}
IREncoder::IREncoder(UINT8 moduleNumber, UINT32 channel) : DigitalInput(moduleNumber , channel)
{
	SetupInterrupts();
}
void IREncoder::SetupInterrupts()
{
	lastTime = 0;
	lastRPM = 0;
	RequestInterrupts(IRInterrupt, this);
	SetUpSourceEdge(true, false);
	EnableInterrupts();
	//printf("IREncoder SetupInturrupts\n");
}

void IREncoder::ProcessInterrupt()
{
		double currentTime = Timer::GetFPGATimestamp();
		double elapsedTime = currentTime - lastTime;
		if (elapsedTime > 0.002)
			lastRPM = ((1.0 / elapsedTime) * 60.0);
		lastTime = currentTime;
		//printf("I WAS HERE!!!\n");
		return;
}
double IREncoder::GetRPM()
{
	return lastRPM;
}

