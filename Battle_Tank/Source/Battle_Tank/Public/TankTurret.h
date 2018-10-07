// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories("Collision", "Physics"))
class BATTLE_TANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void TurretRotation(float ReleativeRotation);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxFloatDistance = 60.f;
	
};
