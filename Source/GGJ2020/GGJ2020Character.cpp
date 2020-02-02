// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GGJ2020Character.h"
#include "GGJ2020Projectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId
#include "CharacterFlags.h"
#include "MyNameIsGameInstance.h"
#include "PickableObject.h"
#include "Door.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AGGJ2020Character

AGGJ2020Character::AGGJ2020Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	HoldingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HoldingComponent"));
	HoldingComponent->SetRelativeLocation(FVector(50.2f, 48.4f, -10.6f));
	HoldingComponent->SetupAttachment(RootComponent);

	CurrentItem = NULL;
	bCanMove = true;
	bInspecting = false;
}

void AGGJ2020Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

void AGGJ2020Character::Tick(float DeltaSeconds)
{

	Super::Tick(DeltaSeconds);

	Start = FirstPersonCameraComponent->GetComponentLocation();
	ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	End = ((ForwardVector * 400.f) + Start);


	if (!bHoldingItem)
	{
		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, DefaultComponentQueryParams, DefaultResponseParam))
		{
			if (Hit.GetActor()->GetClass()->IsChildOf(APickableObject::StaticClass()))
			{
				CurrentItem = Cast<APickableObject>(Hit.GetActor());
			}

			if (Hit.GetActor()->GetClass()->IsChildOf(ADoor::StaticClass()))
			{
				CurrentDoor = Cast<ADoor>(Hit.GetActor());
			}

			if (Hit.GetActor()->GetClass()->IsChildOf(APuzzleDoor::StaticClass()))
			{
				PuzzleDoor = Cast<APuzzleDoor>(Hit.GetActor());
			}
		}
		else
		{
			PuzzleDoor = NULL;
			CurrentItem = NULL;
			CurrentDoor = NULL;
		}
	}

	if (bInspecting)
	{
		if (bHoldingItem)
		{
			FirstPersonCameraComponent->SetFieldOfView(FMath::Lerp(FirstPersonCameraComponent->FieldOfView, 90.0f, 0.1f));
			HoldingComponent->SetRelativeLocation(FVector(0.0f, 50.0f, 50.0f));
			GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMax = 179.9000002f;
			GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMin = -179.9000002f;
			CurrentItem->RotateActor();
		}
		else
		{
			FirstPersonCameraComponent->SetFieldOfView(FMath::Lerp(FirstPersonCameraComponent->FieldOfView, 45.0f, 0.1f));
		}
	}
	else
	{
		FirstPersonCameraComponent->SetFieldOfView(FMath::Lerp(FirstPersonCameraComponent->FieldOfView, 90.0f, 0.1f));

		if (bHoldingItem)
		{
			HoldingComponent->SetRelativeLocation(FVector(50.0f, 0.0f, 0.f));
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGGJ2020Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGGJ2020Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AGGJ2020Character::OnFire);

	// Bind action event
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AGGJ2020Character::OnAction);

	// Bind Inspect event
	//TODO FIX
	//PlayerInputComponent->BindAction("Inspect", IE_Pressed, this, &AGGJ2020Character::OnInspect);
	//PlayerInputComponent->BindAction("Inspect", IE_Released, this, &AGGJ2020Character::OnInspectReleased);

	// Enable touchscreen input
	EnableTouchscreenMovement(PlayerInputComponent);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AGGJ2020Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGGJ2020Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &AGGJ2020Character::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGGJ2020Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGGJ2020Character::LookUpAtRate);
}

void AGGJ2020Character::Jump()
{
	UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());
	if (gameInstance->Flags->CanJump)
	{
		ACharacter::Jump();
	}
}

void AGGJ2020Character::OnFire()
{
	// try and fire a projectile
	/*if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			if (bUsingMotionControllers)
			{
				const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
				const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
				World->SpawnActor<AGGJ2020Projectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			}
			else
			{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AGGJ2020Projectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}*/
}

void AGGJ2020Character::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
	{
		return;
	}
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void AGGJ2020Character::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	TouchItem.bIsPressed = false;
}

void AGGJ2020Character::ToggleItemPickup()
{
	if (CurrentItem)
	{
		bHoldingItem = !bHoldingItem;
		CurrentItem->Pickup();

		if (!bHoldingItem)
		{
			CurrentItem = NULL;
		}
	}
}

void AGGJ2020Character::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//bHolding = false;
}

void AGGJ2020Character::AddControllerYawInput(float Val)
{
	UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());

	//Super::AddControllerYawInput(Val);
	if (Val != 0.f)
	{
		if (!gameInstance->Flags->ControlNormal)
		{
			Super::AddControllerYawInput(Val * -1);
		}
		else
		{
			Super::AddControllerYawInput(Val);
		}
	}
}

void AGGJ2020Character::AddControllerPitchInput(float Val)
{
	UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());

	//Super::AddControllerPitchInput(Val);
	if (Val != 0.f)
	{
		if (!gameInstance->Flags->ControlNormal)
		{
			Super::AddControllerPitchInput(Val * -1);
		}
		else
		{
			Super::AddControllerPitchInput(Val);
		}
	}
}

void AGGJ2020Character::MoveForward(float Value)
{
	UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());

	if (Value != 0.0f)
	{
		if (gameInstance->Flags->ControlNormal)
		{
			// add movement in that direction
			AddMovementInput(GetActorForwardVector(), Value);

		}
		else
		{
			// add movement in that direction
			AddMovementInput(GetActorForwardVector() * -1, Value);
		}
	}

}

void AGGJ2020Character::MoveRight(float Value)
{
	UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());
	if (Value != 0.0f)
	{
		if (gameInstance->Flags->ControlNormal)
		{
			// add movement in that direction
			AddMovementInput(GetActorRightVector(), Value);

		}
		else
		{
			// add movement in that direction
			AddMovementInput(GetActorRightVector() * -1, Value);
		}
	}
}

void AGGJ2020Character::OnAction()
{
	if (CurrentItem && !bInspecting)
	{
		ToggleItemPickup();
	}

	if (CurrentDoor)
	{
		CurrentDoor->ChangeLevel();
	}

	if (PuzzleDoor)
	{
		PuzzleDoor->ChangeLevel();
	}
}


void AGGJ2020Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGGJ2020Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool AGGJ2020Character::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent)
{
	if (FPlatformMisc::SupportsTouchInput() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGGJ2020Character::BeginTouch);
		PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &AGGJ2020Character::EndTouch);

		//Commenting this out to be more consistent with FPS BP template.
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AGGJ2020Character::TouchUpdate);
		return true;
	}
	
	return false;
}
