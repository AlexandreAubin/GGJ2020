// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableObject.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "SnapTriggerBox.h"

// Sets default values
APickableObject::APickableObject()
{
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MyMesh->SetSimulatePhysics(true);
	RootComponent = MyMesh;

	bHolding = false;
	bGravity = true;

	MyMesh->OnComponentBeginOverlap.AddDynamic(this, &APickableObject::BeginOverlap);


}

void APickableObject::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ASnapTriggerBox* triggerbox = Cast<ASnapTriggerBox>(OtherActor);
	if (triggerbox)
	{
		UMyNameIsGameInstance* gameInstance = Cast<UMyNameIsGameInstance>(GetGameInstance());
		if (triggerbox->triggerPuzzleFlag == unlockPuzzleFlag)
		{
			gameInstance->SetFlagPuzzle(unlockPuzzleFlag);
		}
		MyMesh->SetSimulatePhysics(false);
	}
}


// Called when the game starts or when spawned
void APickableObject::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();

	if (MyCharacter)
	{
		TArray<USceneComponent*> Components;

		MyCharacter->GetComponents(Components);

		if (Components.Num() > 0)
		{
			for (auto& Comp : Components)
			{
				if (Comp->GetName() == "HoldingComponent")
				{
					HoldingComp = Cast<USceneComponent>(Comp);
				}
			}
		}
	}


	
}

// Called every frame
void APickableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickableObject::RotateActor()
{
	ControlRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	SetActorRotation(FQuat(ControlRotation));
}

void APickableObject::Pickup()
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

