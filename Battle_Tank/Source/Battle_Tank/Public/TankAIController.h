// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class UTankMovementComponent;

UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

		
public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		UTankMovementComponent* TankMovementComponent = nullptr;
private:
	
	float AcceptanceRadius = 300;
};
