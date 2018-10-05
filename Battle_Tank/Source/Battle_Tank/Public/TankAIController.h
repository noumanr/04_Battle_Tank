// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

		
public:
		virtual void BeginPlay() override;
	
private:

		ATank* GetPlayerControlledTank() const;
		ATank* GetAIControlledTank() const;
};
