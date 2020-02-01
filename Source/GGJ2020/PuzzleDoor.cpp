// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleDoor.h"

// Sets default values
APuzzleDoor::APuzzleDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MyMesh;


	SoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("SoundComponent"));
	SoundComponent->bAutoActivate = true;
	SoundComponent->SetupAttachment(RootComponent);
	SoundComponent->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));

}

void APuzzleDoor::ChangeLevel()
{
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
	SoundComponent->AdjustVolume(1.f, 100.f);
	//Destroy();
}
void APuzzleDoor::BeginPlay()
{
	Super::BeginPlay();

	// Note because the Cue Asset is set to loop the sound,
	// once we start playing the sound, it will play 
	// continiously...
	SoundComponent->VolumeMultiplier = 0.01f;
	SoundComponent->Play();
}

void APuzzleDoor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (SoundToActivate->IsValidLowLevelFast()) {
		SoundComponent->SetSound(SoundToActivate);
	}
}

void APuzzleDoor::Tick(float DeltaSeconds)
{

	//float propRpm = SoundToActivate->lastEngineRpm * SoundToActivate->reductionRatio;
	SoundComponent->SetFloatParameter(FName("pitch"), 1);
}

