	// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AITank = GetAIControlledTank();
		
	if (AITank)
	{

		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller Attached to %s "), *(AITank->GetName()))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Tank Controller Attached to %s "), *(AITank->GetName()))

	}

	ATank* PlayerTank = GetPlayerControlledTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank Found %s "), *(PlayerTank->GetName()))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Found!"))

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

