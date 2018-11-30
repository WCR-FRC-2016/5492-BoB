
#include "RobotMap.h"
#include "OI.h"
#include "RobotDrive.h"
#include "OpenOneMotor.h"
#include <IterativeRobot.h>
#include "OI.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <Robot.h>

// TODO: invalid use of non-static data member lines 17/18/20/21

OpenOneMotor::OpenOneMotor () {

}
WPI_TalonSRX * OpenOneMotor::Open (int DeviceNumber) {
	WPI_TalonSRX * ReturnTalonObj;
	ReturnTalonObj = new WPI_TalonSRX (DeviceNumber);
	ReturnTalonObj->SetInverted(Invert);
	ReturnTalonObj->ConfigPeakCurrentLimit(CurrentLimitAmp, 0);
	ReturnTalonObj->ConfigPeakCurrentDuration(1000,0);
	ReturnTalonObj->ConfigOpenloopRamp(RampTime, 0);
	ReturnTalonObj->EnableCurrentLimit(CurrentLimit);
	ReturnTalonObj->SetSafetyEnabled(true);
	return ReturnTalonObj;
};


