// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MainCharacterAssets.generated.h"

UCLASS()
class GGJ2020_API UMainCharacterAssets : public UObject
{
	GENERATED_BODY()

public:

	UMainCharacterAssets();

	bool CanInteract = false;

	bool IsWalkingNormally = false;

	bool HasFlashLight = false;

	bool CanJump = false;

	bool CanRun = false;

	bool CanSeeColor = false;

	bool CanHearMusic = false;

	
};
