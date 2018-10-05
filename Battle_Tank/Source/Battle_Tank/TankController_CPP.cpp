// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController_CPP.h"

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



	//DrawDebugLine(GetWorld(), PlayerPreviewVector, LineOutVectorLocation, FColor(255, 0, 0), false, 0.f, 0.f, 5.f);
	AimTowardCrosshair();

}

// Aim the turret toward the Cross hair
void ATankController_CPP::AimTowardCrosshair()
{
	   
	FVector HitResult;

	if (GetSightRayHitLocation(HitResult))
	{
		//UE_LOG(LogTemp, Warning, TEXT("This is ticking %s"), *(HitResult.ToString()))
		//TODO Tell the Tank to aim at the point
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

	
	FVector _playerWorldDirection;
		
	if (GetLookDirection(_playerWorldDirection))
	{
		if (GetHitVectorLocation(_playerWorldDirection, OutHitLocation)) // IN Vector for world direction and OUT vector of Impact Point
		{
			UE_LOG(LogTemp, Warning, TEXT("No Tank Controller Attached to %s "), *(OutHitLocation.ToString()))
		}
	}


	return GetHitVectorLocation(_playerWorldDirection, OutHitLocation);
}




// Get the pawn attached to the controller
ATank * ATankController_CPP::GetControlledTank() const
{
	//if (!GetControlledTank()) { return nullptr; }

	return Cast <ATank>(GetPawn());

}

// GetPlayer World Direction or Forward Vector
bool ATankController_CPP::GetLookDirection(FVector& PlayerWorldDirection) const
{
	int32 ViewportX, ViewportY;
	GetViewportSize(ViewportX, ViewportY);
	FVector PlayerWorldLocation; // to be discarded 

	FVector2D ScreenLocation = FVector2D((ViewportX*CrossHairXLocation), (ViewportY*CrossHairYLocation));

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, PlayerWorldLocation, PlayerWorldDirection))
	{
		return true;
	}
	

	return false;
}

bool ATankController_CPP::GetHitVectorLocation(FVector PlayerWorldDirection, FVector& OutHitRayVectorLocation) const {
	FHitResult OutHitRayLocation;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	FVector PlayerPreviewVector;
	FRotator PlayerPreviewRotation;

	PlayerPreviewVector = PlayerCameraManager->GetCameraLocation();
	
	FVector LineOutVectorLocation = (PlayerPreviewVector + (PlayerWorldDirection*LineTraceRange)) ;
	
	///defining the query prams needed for the line trace channel
	FCollisionQueryParams CollisionParams;
	FCollisionResponseParams ResponsePrams;

	GetWorld()->LineTraceSingleByChannel(OutHitRayLocation,
		PlayerPreviewVector,
		LineOutVectorLocation,
		ECollisionChannel(ECC_Visibility),
		CollisionParams,
		ResponsePrams
		);
	///testing the line with debug line
	//DrawDebugLine(GetWorld(), PlayerPreviewVector, LineOutVectorLocation, FColor(255, 0, 0), false, 0.f, 0.f, 5.f);
	 OutHitRayVectorLocation = OutHitRayLocation.Location;

	return OutHitRayLocation.bBlockingHit;
}