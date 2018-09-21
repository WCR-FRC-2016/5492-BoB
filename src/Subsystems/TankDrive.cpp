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
#include "Drive/DifferentialDrive.h"
#include "OI.h"
#include <ctre/Phoenix.h>
#include <Joystick.h>
#include <RobotDrive.h>

WPI_TalonSRX * FrontL;
WPI_TalonSRX * FrontR;
WPI_TalonSRX * BackL;
WPI_TalonSRX * BackR;
DifferentialDrive * _diffDrive;
TankDrive::TankDrive() : frc::Subsystem("TankDrive"){

	FrontL = new WPI_TalonSRX (frontLeftDrive);
	FrontR = new WPI_TalonSRX (frontRightDrive);
	BackL = new WPI_TalonSRX (backLeftDrive);
	BackR = new WPI_TalonSRX (backRightDrive);
	_diffDrive = new DifferentialDrive(FrontL, FrontR);

	FrontR->SetInverted(true);
	BackR->SetInverted(true);

	BackL->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, frontLeftDrive);
	BackR->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, frontRightDrive);

}
void TankDrive::ArcadeDrive(double xAxis, double yAxis)
{
	double parsedLeft;
	double parsedRight;
	double parsedX;
	double parsedY;
	double power = 2.3;
	//Setting inputs to a power
	parsedX = pow(abs(xAxis), power) * (xAxis / abs(xAxis));

	parsedY = pow(abs(yAxis), power) * (yAxis / abs(yAxis));

	if (xAxis > 0)
	{
		//Turning Left?
		if (yAxis > 0)
		{
			parsedLeft = parsedY - parsedX;
			parsedRight = (parsedY > parsedX)?parsedY:parsedX;
		}
		else
		{

		}
	}

	_diffDrive->TankDrive(-1 *parsedLeft, -1 *parsedRight);
}

void TankDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
