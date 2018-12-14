/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DoWeEvenLift.h"
#include "../RobotMap.h"
#include "OpenOneMotor.h"
#include "Commands/TeleopLift.h"
#include <Robot.h>
#include "OI.h"
#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include <IterativeRobot.h>
#include <iostream>
WPI_TalonSRX* LiftLeader;
WPI_TalonSRX* LiftFollower;
DoWeEvenLift::DoWeEvenLift() : frc::Subsystem("DoWeEvenLift") {
}

void DoWeEvenLift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	if (!initialized) {
		DoWeEvenLift::DoWeEvenLiftInitialize();
	}

	Robot::m_doweevenlift.SetDefaultCommand(new TeleopLift());

}

void DoWeEvenLift::DoWeEvenLiftInitialize() {
	OpenOneMotor* OpenLiftMotor = new OpenOneMotor();

	OpenLiftMotor->CurrentLimitAmp=50;

	LiftFollower = OpenLiftMotor->Open(elevator2);
	OpenLiftMotor->Invert = true;
	LiftLeader = OpenLiftMotor->Open(elevator1);
	LiftFollower->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, elevator1);
	initialized = true;

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void DoWeEvenLift::ManualLift(double joystick) {
	if (joystick < 0) {
		joystick = joystick / 1;
	}
	else {
		joystick = joystick / 1.5;
	}
	LiftLeader->Set(-joystick);
}
