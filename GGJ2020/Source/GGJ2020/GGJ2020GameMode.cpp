// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GGJ2020GameMode.h"
#include "GGJ2020HUD.h"
#include "GGJ2020Character.h"
#include "UObject/ConstructorHelpers.h"

AGGJ2020GameMode::AGGJ2020GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGGJ2020HUD::StaticClass();
}
