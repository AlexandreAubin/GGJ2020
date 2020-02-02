// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

#include "PuzzleDoor.generated.h"

UCLASS()
class GGJ2020_API APuzzleDoor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	APuzzleDoor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
	UAudioComponent* SoundComponent;

	UPROPERTY(EditAnywhere)
	USoundCue* SoundToActivate;

	UFUNCTION(Category = "Sound", BlueprintImplementableEvent, BlueprintCallable)
	void PlaySoundDoor();


	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FString LevelName = TEXT("");

	void ChangeLevel();
};
