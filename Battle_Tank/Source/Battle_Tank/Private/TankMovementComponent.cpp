// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"




//This method assign the Tank tracks to the pointers to be used in pushing and rotating tank
void UTankMovementComponent::Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

//Takes the input Value from the Input Manager and Add use them to move tank forward or backward
void UTankMovementComponent::IntendMoveForward(float Force)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottleRequest(Force);
	RightTrack->SetThrottleRequest(Force);


}

//Takes the input Value from the Input Manager and Add use them to rotate the tank
void UTankMovementComponent::IntendTurn(float Force)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottleRequest(-Force);
	RightTrack->SetThrottleRequest(Force);


}
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//if (!LeftTrack || !RightTrack) { return; }
	auto AITankForwardVector = MoveVelocity.GetSafeNormal();
	auto TankForwardDirection = GetOwner()->GetActorForwardVector();

	// getting Dot Product of the Vectors
	auto AITankForce = FVector::DotProduct(AITankForwardVector, TankForwardDirection);
	MoveAITank(AITankForce);
	//getting Cross Product to Make Tank Turn
	auto AITankTurnForce = FVector::CrossProduct(AITankForwardVector, TankForwardDirection);

	IntendTurn(AITankTurnForce.Z);
	//float Time = GetWorld()->GetTimeSeconds();
	
//	UE_LOG(LogTemp, Warning, TEXT("%s is moving at Velocity is : %f"), *(GetOwner()->GetName()), TheZForce)

		return;
}

void UTankMovementComponent::MoveAITank(float Throw)
{

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottleRequest(Throw);
	RightTrack->SetThrottleRequest(Throw);
	//UE_LOG(LogTemp, Warning, TEXT("%s is moving at Velocity is : %f"), *(GetOwner()->GetName()), Throw)
}