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
#include "../Commands/TeleOpTankDrive.h"
#include <iostream>
#include <Robot.h>

WPI_TalonSRX * FrontL;
WPI_TalonSRX * FrontR;
WPI_TalonSRX * BackL;
WPI_TalonSRX * BackR;

DifferentialDrive * _diffDrive;
TankDrive::TankDrive() : frc::Subsystem("TankDrive"){
}
void TankDrive::ArcadeDrive(double xAxis, double yAxis)
{
	double parsedLeft;
	double parsedRight;
	double parsedX;
	double parsedY;
	double power = 2.3;
	//Setting inputs to a power
	parsedX = pow((xAxis>0)?xAxis:-xAxis, power) * (xAxis / (xAxis>0)?xAxis:-xAxis);

	parsedY = pow((yAxis>0)?yAxis:-yAxis, power) * (yAxis / (yAxis>0)?yAxis:-yAxis);

	if (yAxis < 0) // forward back
	{
		//TO BE
		//FILLED IN
		//Turning Left?
		if (xAxis > 0) //right forwards
		{
			parsedLeft = parsedY - parsedX;
			parsedRight = (parsedY > parsedX)?parsedY:parsedX;
		}
		else //left forwards
		{
			parsedLeft = (-parsedY > -parsedX)?parsedY:-parsedX;
			parsedRight = parsedY + parsedX;
		}
	}
	else //backwards
	{
		if (xAxis > 0) //right
		{
			parsedLeft = (-parsedY > parsedX)?parsedY:-parsedX;
			parsedRight = parsedY + parsedX;
		}
		else //left
		{
			parsedLeft = parsedY - parsedX;
			parsedRight = (parsedY > -parsedX)?parsedY:parsedX;
		}
	}
	printf("heyheyheygeyegeygeygey");
	_diffDrive->TankDrive(-parsedLeft, parsedRight);

}
void TankDrive::TankDriveInitialize()
{
	initialized = true;
	FrontL = new WPI_TalonSRX (frontLeftDrive);
		FrontR = new WPI_TalonSRX (frontRightDrive);
		BackL = new WPI_TalonSRX (backLeftDrive);
		BackR = new WPI_TalonSRX (backRightDrive);
		_diffDrive = new DifferentialDrive (*FrontL, *FrontR);

		FrontR->SetInverted(true);
		FrontL->SetInverted(false);
		BackR->SetInverted(true);
		BackL->SetInverted(false);

		FrontR->ConfigPeakCurrentLimit(50,0);
		FrontL->ConfigPeakCurrentLimit(50,0);
		BackR->ConfigPeakCurrentLimit(50,0);
		BackL->ConfigPeakCurrentLimit(50,0);

		FrontR->ConfigPeakCurrentDuration(1000,0);
		FrontL->ConfigPeakCurrentDuration(1000,0);
		BackR->ConfigPeakCurrentDuration(1000,0);
		BackL->ConfigPeakCurrentDuration(1000,0);

		FrontR->ConfigOpenloopRamp(.3,0);
		FrontL->ConfigOpenloopRamp(.3,0);
		BackR->ConfigOpenloopRamp(.3,0);
		BackL->ConfigOpenloopRamp(.3,0);

		FrontR->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);
		FrontL->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);

		FrontR->EnableCurrentLimit(true);
		FrontL->EnableCurrentLimit(true);
		BackR->EnableCurrentLimit(true);
		BackL->EnableCurrentLimit(true);


		//PID BTW
		FrontR->Config_kP(0, RightP, 0);
		FrontR->Config_kI(0, RightI, 0);
		FrontR->Config_kD(0, RightD, 0);
		FrontL->Config_kP(0, LeftP, 0);
		FrontL->Config_kI(0, LeftI, 0);
		FrontL->Config_kD(0, LeftD, 0);

		FrontR->ConfigNominalOutputForward(NominalOutput, 0);
		FrontR->ConfigNominalOutputReverse(-NominalOutput, 0);
		FrontL->ConfigNominalOutputForward(NominalOutput, 0);
		FrontL->ConfigNominalOutputReverse(-NominalOutput, 0);

		FrontR->SetSensorPhase(false);
		FrontL->SetSensorPhase(false);


		FrontR->ConfigPeakOutputForward(MaxOutput, 0);
		FrontR->ConfigPeakOutputReverse(-MaxOutput, 0);
		FrontL->ConfigPeakOutputForward(MaxOutput, 0);
		FrontL->ConfigPeakOutputReverse(-MaxOutput, 0);

		FrontR->ConfigNeutralDeadband(PIDDeadband, 0);
		FrontL->ConfigNeutralDeadband(PIDDeadband, 0);

		FrontR->SetSelectedSensorPosition(0,0,0);
		FrontL->SetSelectedSensorPosition(0,0,0);

		_diffDrive->SetSafetyEnabled(false);
		BackL->SetSafetyEnabled(false);
		BackR->SetSafetyEnabled(false);
		_diffDrive->SetExpiration(.5);

		BackL->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, frontLeftDrive);
		BackR->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, frontRightDrive);
}

void TankDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	if (!initialized) {
		TankDrive::TankDriveInitialize();
	}
	Robot::m_tankdrive.SetDefaultCommand(new TeleOpTankDrive());









}

// Put methods for controlling this subsystem
// here. Call these from Commands.
