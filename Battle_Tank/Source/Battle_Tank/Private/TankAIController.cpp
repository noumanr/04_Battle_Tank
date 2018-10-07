	// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* AITank = GetAIControlledTank();
	ATank* PlayerTank = GetPlayerControlledTank();

	if (AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller Attached to %s "), *(AITank->GetName()))
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Tank Controller Attached to %s "), *(AITank->GetName()))

	}


	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player found to %s "), *(PlayerTank->GetName()))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Found!"))

	}
}
	
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = GetPlayerControlledTank();
	
	
	
	auto ThisTankName = GetAIControlledTank()->GetName();


	if (PlayerTank)
	{
		FVector PlayerLocation = PlayerTank->GetActorLocation();
		GetAIControlledTank()->AimAtTank(PlayerLocation);

		//UE_LOG(LogTemp, Error, TEXT("%s is aiming at  %s "), *ThisTankName, *(PlayerLocation.ToString()))
	}
	
}


ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast <ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerControlledTank() const
{
	auto TempPlayer = GetWorld()->GetFirstLocalPlayerFromController()->GetPlayerController(GetWorld())->GetPawn();
	if (!TempPlayer) { return nullptr; }
	return Cast <ATank>(TempPlayer);
}

