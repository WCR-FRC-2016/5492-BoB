#pragma once
#include <ctre/Phoenix.h>
class OpenOneMotor {

public:
	bool Invert = false;
	bool CurrentLimit = true;
	int RampTime = 0;
	int CurrentLimitAmp = 15;
	WPI_TalonSRX * Open (int DeviceNumber);

private:

};
