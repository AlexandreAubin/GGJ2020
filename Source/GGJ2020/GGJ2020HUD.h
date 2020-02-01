// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GGJ2020HUD.generated.h"

UCLASS()
class AGGJ2020HUD : public AHUD
{
	GENERATED_BODY()

public:
	AGGJ2020HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

