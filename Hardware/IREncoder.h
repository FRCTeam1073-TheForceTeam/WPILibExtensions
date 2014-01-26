#ifndef IR_ENCODER_H
#define IR_ENCODER_H
#include "WPILib.h"

class IREncoder : public DigitalInput{
public:
	explicit IREncoder(UINT32 channel);
	IREncoder(UINT8 moduleNumber, UINT32 channel);
	void ProcessInterrupt();
	double GetRPM();
private:
	void SetupInterrupts();
	double lastTime;
	double lastRPM;
protected:
	
};
#endif
