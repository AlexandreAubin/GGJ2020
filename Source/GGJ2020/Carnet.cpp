// Fill out your copyright notice in the Description page of Project Settings.


#include "Carnet.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "SnapTriggerBox.h"


// Sets default values
ACarnet::ACarnet()
{

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//MyMesh->SetSimulatePhysics(true);
	RootComponent = MyMesh;

	bHolding = false;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACarnet::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	/*ASnapTriggerBox* triggerbox = Cast<ASnapTriggerBox>(OtherActor);
	if (triggerbox)
	{
		UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());
		if (triggerbox->triggerPuzzleFlag == unlockPuzzleFlag)
		{
			gameInstance->SetFlagPuzzle(unlockPuzzleFlag);
		}
		MyMesh->SetSimulatePhysics(false);
	}*/
}


// Called when the game starts or when spawned
void ACarnet::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	//PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();

	if (MyCharacter)
	{
		TArray<USceneComponent*> Components;

		MyCharacter->GetComponents(Components);

		if (Components.Num() > 0)
		{
			for (auto& Comp : Components)
			{
				if (Comp->GetName() == "CarnetHoldingComponent")
				{
					HoldingComp = Cast<USceneComponent>(Comp);
				}
			}
		}
	}



}

// Called every frame
void ACarnet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarnet::RotateActor()
{
	ControlRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	SetActorRotation(FQuat(ControlRotation));
}

void ACarnet::Pickup()
{
	bHolding = !bHolding;
	bGravity = !bGravity;
	MyMesh->SetEnableGravity(bGravity);
	MyMesh->SetSimulatePhysics(bHolding ? false : true);
	MyMesh->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
	if (HoldingComp && bHolding)
	{
		MyMesh->AttachToComponent(HoldingComp, FAttachmentTransformRules::KeepWorldTransform);
		SetActorLocation(HoldingComp->GetComponentLocation());
	}

	if (!bHolding)
	{
		MyMesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		ForwardVector = PlayerCamera->GetForwardVector();
		MyMesh->AddForce(ForwardVector * 100000 * MyMesh->GetMass());
	}
}