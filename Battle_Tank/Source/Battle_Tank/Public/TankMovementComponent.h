// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;


	void MoveAITank(float Throw);
	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendMoveForward(float Force);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendTurn(float Force);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
		
	UTankTracks* LeftTrack = nullptr;
	UTankTracks* RightTrack = nullptr;

private:
	//float AITankForce;

};
