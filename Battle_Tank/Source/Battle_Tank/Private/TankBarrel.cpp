// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Battle_Tank.h"


void UTankBarrel::Elevate(float DegreePerSec)
{
	// use the yaw values to rotate the barrel
		// and Yaw/up-down rotation will be done on barrel
	UE_LOG(LogTemp, Warning, TEXT("The Barrel speed %f"), DegreePerSec)
}