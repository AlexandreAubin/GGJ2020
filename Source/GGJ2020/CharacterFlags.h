// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GGJ2020_API CharacterFlags
{
public:
	CharacterFlags();
	~CharacterFlags();

	bool CanRun = false;
	bool CanJump = false;
	bool CanInteract = false;
	bool ControlNormal = false;
};
