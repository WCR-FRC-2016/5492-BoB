/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TeleOpTankDrive.h"
#include "TankDrive.h"
#include "../RobotMap.h"
#include "OI.h"
#include "RobotDrive.h"
#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include <IterativeRobot.h>

#include "OI.h"
#include <ctre/Phoenix.h>
#include <TankDrive.h>
#include <Joystick.h>
#include <RobotDrive.h>
TeleOpTankDrive::TeleOpTankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(frc::Subsystem("TankDrive"));
}

// Called just before this Command runs the first time
void TeleOpTankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpTankDrive::Execute() {

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
