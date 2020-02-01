// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CharacterFlags.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

#include "MyNameIsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GGJ2020_API UMyNameIsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	virtual void Init() override;

	virtual void StartGameInstance() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UCharacterFlags* Flags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Music)
	USoundCue* MainMusic;

};
 