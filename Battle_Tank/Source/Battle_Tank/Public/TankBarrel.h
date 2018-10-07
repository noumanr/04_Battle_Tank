// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent),hideCategories("Collision","Physics"))
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	void Elevate(float DegreePerSec);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxFloatDistance = 2.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegrees = 20.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegrees = -5.f;
};
