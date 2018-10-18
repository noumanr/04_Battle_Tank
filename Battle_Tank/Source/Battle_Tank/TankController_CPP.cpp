// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController_CPP.h"
#include "Tank.h"

void ATankController_CPP::BeginPlay()
{
	Super::BeginPlay();

		ATank* TempTank = GetControlledTank();
		

		if (TempTank)
		{
			
			UE_LOG(LogTemp, Warning, TEXT("This is Player Tank Controller Attached to %s "), *(TempTank->GetName()))
		}
		else
		{
			FString TempTankName = TempTank->GetOwner()->GetName();
			UE_LOG(LogTemp, Warning, TEXT("No Tank Controller Attached to %s "), *(TempTank->GetName()))

		}
}

void ATankController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardCrosshair();

}

// Aim the turret toward the Cross hair
void ATankController_CPP::AimTowardCrosshair()
{
	   
	FVector OutHitLocation;
	if (!GetControlledTank()) { return; }
	if (GetSightRayHitLocation(OutHitLocation))
	{
		GetControlledTank()->AimAtTank(OutHitLocation);
	}
	else
	{
		return;
	}

	return;
}

//Returns the Impact point Vector of the LineTrace / RayCast

bool ATankController_CPP::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportX, ViewportY;
	GetViewportSize(ViewportX, ViewportY);
	

	FVector2D ScreenLocation = FVector2D((ViewportX*CrossHairXLocation), (ViewportY*CrossHairYLocation));
	
	FVector PlayerWorldDirection;
		
	if (GetLookDirection(ScreenLocation, PlayerWorldDirection))
	{
		GetHitVectorLocation(PlayerWorldDirection, OutHitLocation); // IN Vector for world direction and OUT vector of Impact Point
		
	}


	return true;
}




// Get the pawn attached to the controller
ATank * ATankController_CPP::GetControlledTank() const
{
	//

	return Cast <ATank>(GetPawn());

}

// GetPlayer World Direction or Forward Vector
bool ATankController_CPP::GetLookDirection(FVector2D ScreenLocation, FVector& PlayerWorldDirection) const
{
	FVector PlayerWorldLocation; // to be discarded 

	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, PlayerWorldLocation, PlayerWorldDirection));
	
}

bool ATankController_CPP::GetHitVectorLocation(FVector LookDirection, FVector& OutHitRayVectorLocation) const {
	
	FHitResult OutHitRayLocation;//out hit result 
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	FVector StartLocation = PlayerCameraManager->GetCameraLocation();


	FVector EndLocation = (StartLocation + (LookDirection*LineTraceRange)) ;
	
	///defining the query prams needed for the line trace channel
	FCollisionQueryParams CollisionParams;
	FCollisionResponseParams ResponsePrams;


	GetWorld()->LineTraceSingleByChannel(
		OutHitRayLocation,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Camera);

	///testing the line with debug line
	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor(255, 0, 0), false, 0.f, 0.f, 5.f);

	OutHitRayVectorLocation = OutHitRayLocation.Location;
	return OutHitRayLocation.bBlockingHit;
}