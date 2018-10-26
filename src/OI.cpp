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


OI::OI() {

	 _driverStick = 0;
		//JoystickButton * driveButton1 = new JoystickButton(_driverStick, 1);
	// Process operator interface input here.

}
void OI::OIInit(){
	if (_driverStick == 0)
	{
		_driverStick = new frc::XboxController(0);
	}
}

double OI::ReturnDriverXAxis(){
	return _driverStick->GetX(frc::GenericHID::kRightHand);

}
double OI::ReturnDriverYAxis(){
	return _driverStick->GetY(frc::GenericHID::kLeftHand);
}

