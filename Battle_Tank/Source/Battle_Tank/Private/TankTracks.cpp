// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




void UTankTracks::SetThrottleRequest(float Throttle)
{

	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %s is throtling : %f "), *Name, Throttle)

		auto ForceForward = GetForwardVector()*Throttle*MaxTrackThrottle;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceForward, ForceLocation);
}	 