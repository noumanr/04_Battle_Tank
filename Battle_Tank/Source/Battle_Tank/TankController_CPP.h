// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"
#include "TankController_CPP.generated.h"

class ATank;

UCLASS()
class BATTLE_TANK_API ATankController_CPP : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
private:
	virtual void Tick(float DeltaTime) override;

	
	virtual void BeginPlay() override;



	// Tells the Tank Turret controller to hit at the cross hair
	// in the world.
	void AimTowardCrosshair();
	bool GetHitVectorLocation(FVector PlayerWorldDirection, FVector& OutHitRayVectorLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& PlayerWorldDirection) const;
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 2000000.f;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .3333;

};
