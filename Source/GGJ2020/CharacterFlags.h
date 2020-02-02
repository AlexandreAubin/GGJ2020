// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterFlags.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GGJ2020_API UCharacterFlags : public UObject
{
	GENERATED_BODY()
public:

	UCharacterFlags();
	~UCharacterFlags();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Flags)
	bool CanRun = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Flags)
	bool CanJump = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Flags)
	bool CanInteract = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Flags)
	bool ControlNormal = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Flags)
	bool CanSeeColor = false;
};
