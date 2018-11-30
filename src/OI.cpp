/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>
#include <Joystick.h>
#include <XboxController.h>
#include <GenericHID.h>
#include <DriverStation.h>
double tempX, tempY;
OI::OI() {

	 _driverStick = 0;
	 _manualStick = 0;
		//JoystickButton * driveButton1 = new JoystickButton(_driverStick, 1);
	// Process operator interface input here.

}
void OI::OIInit(){
	if (_driverStick == 0)
	{
		_driverStick = new frc::XboxController(0);
	}
	if (_manualStick == 0)
	{
		_manualStick = new frc::XboxController(1);
	}
}

double OI::ReturnDriverXAxis(){
	return DeadBand(_driverStick->GetX(frc::GenericHID::kRightHand));

}
double OI::ReturnDriverYAxis(){
	return DeadBand(_driverStick->GetY(frc::GenericHID::kLeftHand));
}

double OI::DeadBand(double joystick) {
	if (-0.2 < joystick && joystick < 0.2) {
		joystick = 0;
	}
		return joystick;
}

double OI::ReturnManualLeftYAxis(){
	return DeadBand(_manualStick->GetY(frc::GenericHID::kLeftHand));
}
