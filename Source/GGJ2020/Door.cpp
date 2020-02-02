// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/Material.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "MyNameIsGameInstance.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MyMesh;


	SoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("SoundComponent"));
	SoundComponent->bAutoActivate = true;
	SoundComponent->SetupAttachment(RootComponent);
	SoundComponent->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));

}

void ADoor::ChangeLevel()
{
	UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());
	if (flag != EFlagsToUnlock::None)
	{
		gameInstance->SetFlagToUnlock(flag);
	}
	PlaySoundDoor();
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
	SoundComponent->AdjustVolume(1.f, 100.f);

}
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// Note because the Cue Asset is set to loop the sound,
	// once we start playing the sound, it will play 
	// continiously...
	SoundComponent->VolumeMultiplier = 0.01f;
	SoundComponent->Play();
}

void ADoor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (SoundToActivate->IsValidLowLevelFast()) {
		SoundComponent->SetSound(SoundToActivate);
	}
}

void ADoor::Tick(float DeltaSeconds)
{
	
	//float propRpm = SoundToActivate->lastEngineRpm * SoundToActivate->reductionRatio;
	SoundComponent->SetFloatParameter(FName("pitch"), 1);
}




