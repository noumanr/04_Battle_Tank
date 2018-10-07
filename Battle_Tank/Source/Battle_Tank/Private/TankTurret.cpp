// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::TurretRotation(float RealtiveSpeed)
{
	//float ClampedReletiveRotationSpeed = FMath::Clamp<float>(ReleativeRotation, -1., 1.);
	auto RotationChange = RealtiveSpeed * MaxFloatDistance * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
//	auto Time = GetWorld()->GetTimeSeconds();

	FRotator NormalizedRotator = FRotator(0, RawNewRotation, 0);
	NormalizedRotator = NormalizedRotator.GetNormalized();
	SetRelativeRotation(NormalizedRotator);

//	UE_LOG(LogTemp, Warning, TEXT ("%f This is being called %f"),Time, RotationChange)	
}

	

