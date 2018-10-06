// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAtTank(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FCollisionResponseParams CollisionResponse (ECollisionResponse::ECR_Block);

	TArray <AActor*> temp;
	FVector StartLocation = Barrel->GetSocketLocation(FName("FireSocket"));
	FVector TossVelocity;

	//Get the Toss Velocity , if successful it will return true
	bool bHaveAimingSoution = GamePlayStatistics->SuggestProjectileVelocity(
		GetOwner(), 
		TossVelocity, 
		StartLocation, 
		HitLocation, // RayCast hit Location
		LaunchSpeed, //derived from the blueprint
		false,
		0.f,
		0,
		ESuggestProjVelocityTraceOption::TraceFullPath,
		CollisionResponse,
		temp, // might be risky a null Actor array
		true // draw the debug line
	);

	if (bHaveAimingSoution)
	{
		FVector AimDirection = TossVelocity.GetSafeNormal(); //Return the Safe Normal, don't know why need to study
		MoveBarrel(AimDirection);
	}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}
void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimDirection - BarrelRotator;
	UE_LOG (LogTemp, Warning, TEXT ("The Barrel Rotator %s"), *DeltaRotator.ToString())
	//Need to get value from screen space
	// deporject those value in a 3d vector
	// use those pitch value to rotate the turret


		// use the yaw values to rotate the barrel
		// and Yaw/up-down rotation will be done on barrel
			
}