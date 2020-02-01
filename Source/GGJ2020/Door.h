// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class GGJ2020_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;


protected:

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FString LevelName = TEXT("");

	void ChangeLevel();

};
