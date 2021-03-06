/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TeleopLift.h"
#include "../Robot.h"
#include "OI.h"
// TODO: Everything please!

TeleopLift::TeleopLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::m_doweevenlift);

}

// Called just before this Command runs the first time
void TeleopLift::Initialize() {
	Robot::m_doweevenlift.DoWeEvenLiftInitialize();

}

// Called repeatedly when this Command is scheduled to run
void TeleopLift::Execute() {
	Robot::m_doweevenlift.ManualLift(Robot::m_oi.ReturnManualLeftYAxis());
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopLift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopLift::Interrupted() {

}
