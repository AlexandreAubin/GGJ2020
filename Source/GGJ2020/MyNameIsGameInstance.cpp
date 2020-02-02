// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNameIsGameInstance.h"
#include "CharacterFlags.h"
#include "Kismet/GameplayStatics.h"

void UMyNameIsGameInstance::Init()
{
	Super::Init();

	Flags = NewObject<UCharacterFlags>();
	// it, and its parameters from code.
	//MainMusicAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PropellerAudioComp"));
}

void UMyNameIsGameInstance::StartGameInstance()
{
	Super::StartGameInstance();
}

