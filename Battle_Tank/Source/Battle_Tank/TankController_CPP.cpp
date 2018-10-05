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
		UE_LOG(LogTemp, Warning, TEXT("This is ticking %s"), *(HitResult.ToString()))
		//TODO Tell the Tank to aim at the point
	}
	else
	{
		return;
	}
		
	
		// cast a ray to the world
	// get the hit location vector out
	//log the value

	return;
}

//Returns the Impact point Vector of the LineTrace / RayCast

bool ATankController_CPP::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	FHitResult OutHitRayLocation;
	FCollisionQueryParams TraceParameters (FName(TEXT("")), false, GetOwner());

	FVector PlayerPreviewVector;
	FRotator PlayerPreviewRotation;
	FVector OffsetVector = FVector(0., 0., 4500.3f);
	GetPlayerViewPoint(PlayerPreviewVector, PlayerPreviewRotation);

	FVector LineOutVectorLocation = (PlayerPreviewVector + (PlayerPreviewRotation.Vector()*Reach)) + OffsetVector;

	


	GetWorld()->LineTraceSingleByObjectType(OUT OutHitRayLocation,
		PlayerPreviewVector,
		LineOutVectorLocation,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic),
		TraceParameters
	);
	
	OutHitLocation = OutHitRayLocation.ImpactPoint;
	return OutHitRayLocation.bBlockingHit;
}




// Get the pawn attached to the controller
ATank * ATankController_CPP::GetControlledTank() const
{
	//if (!GetControlledTank()) { return nullptr; }

	return Cast <ATank>(GetPawn());

}
