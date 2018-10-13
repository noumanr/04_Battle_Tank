// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;  //TODO should this tick
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

void UTankAimingComponent::AimAtTank(FVector OutHitRayVectorLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	if (!Turret) { return; }

	FVector StartLocation = Barrel->GetSocketLocation(FName("FireSocket"));
	FVector TossVelocity;

	//Get the Toss Velocity , if successful it will return true
	bool bHaveAimingSoution = GamePlayStatics->SuggestProjectileVelocity(
		this,
		TossVelocity,
		StartLocation,
		OutHitRayVectorLocation, // RayCast hit Location
		LaunchSpeed, //derived from the blueprint
		false,
		0.f,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimingSoution)
	{
		FVector AimDirection = TossVelocity.GetSafeNormal(); //Return the Safe Normal, don't know why need to study
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%s Aim Solution Found "), *(OutHitRayVectorLocation.ToString()))
		
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Error, TEXT("%f No Aim Solution Found "), Time)
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{	
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretRefernce(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch); 
	
}
void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - TurretRotator;

	Turret->TurretRotation(DeltaRotator.Yaw);




}