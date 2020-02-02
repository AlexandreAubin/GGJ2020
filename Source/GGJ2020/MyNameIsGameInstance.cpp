// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNameIsGameInstance.h"
#include "CharacterFlags.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

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

void UMyNameIsGameInstance::SetFlagToUnlock(EFlagsToUnlock flag)
{
	switch (flag)
	{
	case(EFlagsToUnlock::UnlockJump):
		Flags->CanJump = true;
		GEngine->AddOnScreenDebugMessage(-1, 19.5f, FColor::Red, TEXT("You remember how to jump..."));
		break;
	case(EFlagsToUnlock::UnlockNormalWalking):
		Flags->ControlNormal = true;
		GEngine->AddOnScreenDebugMessage(-1, 19.5f, FColor::Red, TEXT("You remember how to walk properly..."));
		break;
	case(EFlagsToUnlock::UnlockRun):
		Flags->CanRun = true;
		GEngine->AddOnScreenDebugMessage(-1, 19.5f, FColor::Red, TEXT("You remember how to run..."));
		break;
	case(EFlagsToUnlock::UnlockColor):
		Flags->CanRun = true;
		GEngine->AddOnScreenDebugMessage(-1, 19.5f, FColor::Red, TEXT("THe color are coming back..."));
		break;
	}

}

void UMyNameIsGameInstance::SetFlagPuzzle(EFlagsForPuzzle flag)
{
	switch (flag)
	{
	case(EFlagsForPuzzle::PuzzleFlag1):
		Flags->puzzleFlag1 = true;
		break;
	case(EFlagsForPuzzle::PuzzleFlag2):
		Flags->puzzleFlag2 = true;
		break;
	case(EFlagsForPuzzle::PuzzleFlag3):
		Flags->puzzleFlag3 = true;
		break;

	}
}

