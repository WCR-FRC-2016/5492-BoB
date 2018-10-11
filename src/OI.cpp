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


OI::OI() {
	_driverStick = 0;

	// Process operator interface input here.

}

double OI::ReturnDriverXAxis(){
	return _driverStick->GetX(frc::GenericHID::kLeftHand);
}
double OI::ReturnDriverYAxis(){
	return _driverStick->GetY(frc::GenericHID::kRightHand);
}
void OI::InitButtons(){
	 _driverStick = new XboxController(0);
	 JoystickButton * driveButton1 = new JoystickButton(_driverStick, 1);
}
