// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"



void UTankBarrel::Elevate(float RelativeSpeed)
{
	// use the yaw values to rotate the barrel
		// and Yaw/up-down rotation will be done on barrel
	float ClampedReletiveSpeed = FMath::Clamp<float>(RelativeSpeed, -1., 1.);
	auto ElevationChange = ClampedReletiveSpeed * MaxFloatDistance * GetWorld()->DeltaTimeSeconds;
	auto RawElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawElevation, MinDegrees, MaxDegrees);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));

}	