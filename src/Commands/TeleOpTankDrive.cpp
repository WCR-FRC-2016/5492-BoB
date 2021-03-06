/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TeleOpTankDrive.h"
#include "../Robot.h"
#include "OI.h"



TeleOpTankDrive::TeleOpTankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::m_tankdrive);
}

// Called just before this Command runs the first time
void TeleOpTankDrive::Initialize() {
	Robot::m_tankdrive.TankDriveInitialize();
}

// Called repeatedly when this Command is scheduled to runTankDriveInitiatlize()
void TeleOpTankDrive::Execute() {
	Robot::m_tankdrive.ArcadeDrive(Robot::m_oi.ReturnDriverXAxis(),Robot::m_oi.ReturnDriverYAxis());

}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpTankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpTankDrive::Interrupted() {

}
