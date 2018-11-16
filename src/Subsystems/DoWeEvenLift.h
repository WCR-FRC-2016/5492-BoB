/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

class DoWeEvenLift : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool initialized = false;
	WPI_TalonSRX* LiftLeader;
    WPI_TalonSRX* LiftFollower;
public:
	DoWeEvenLift();
	void InitDefaultCommand() override;
	void DoWeEvenLiftInitialize();

};

