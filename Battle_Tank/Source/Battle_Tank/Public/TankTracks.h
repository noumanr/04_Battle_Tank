// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * Tank Track is use to apply force to the Tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetThrottleRequest(float Throttle);
	UPROPERTY(EditDefaultsOnly, Category = Fire)
		float MaxTrackThrottle = 400000;

};
