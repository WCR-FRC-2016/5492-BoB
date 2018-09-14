/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TankDrive.h"
#include "../RobotMap.h"
#include "OI.h"
#include "RobotDrive.h"
#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include <IterativeRobot.h>

#include "OI.h"
#include <ctre/Phoenix.h>

#include <Joystick.h>
#include <RobotDrive.h>

TankDrive::TankDrive() : frc::Subsystem("TankDrive"){

	WPI_TalonSRX FrontL = new WPI_TalonSRX (frontLeftDrive);
	WPI_TalonSRX FrontR = new WPI_TalonSRX (frontRightDrive);
	WPI_TalonSRX BackL = new WPI_TalonSRX (backLeftDrive);
	WPI_TalonSRX BackR = new WPI_TalonSRX (backRightDrive);

	FrontR.SetInverted(true);
	BackR.SetInverted(true);

	BackL.Set(ctre::phoenix::motorcontrol::ControlMode::Follower, 1);
	BackR.Set(ctre::phoenix::motorcontrol::ControlMode::Follower, 2);

}

void TankDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
