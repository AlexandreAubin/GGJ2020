// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyNameIsGameInstance.h"

#include "SnapTriggerBox.generated.h"


class AActor;

/**
 * 
 */
UCLASS()
class GGJ2020_API ASnapTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public: 

	/** Holding Component */
	UPROPERTY(EditAnywhere)
	class USceneComponent* HoldingComponent;

	/** Holding Component */
	UPROPERTY(EditAnywhere)
	FString TagName;

	void SetComponent(UStaticMeshComponent* mesh);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	EFlagsForPuzzle triggerPuzzleFlag = EFlagsForPuzzle::None;

protected:
	virtual void BeginPlay();
	
};
