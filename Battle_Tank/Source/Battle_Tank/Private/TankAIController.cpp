	// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankMovementComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
	
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* AITank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast <ATank>(GetWorld()->GetFirstLocalPlayerFromController()->GetPlayerController(GetWorld())->GetPawn());
	
	if (!AITank) { return; }
	if (!PlayerTank) { return; }
	auto ThisTankName = AITank->GetName();

	//TODO Move toward the player

	if (PlayerTank)
	{
		
		MoveToActor(PlayerTank, AcceptanceRadius);
		UE_LOG(LogTemp, Warning, TEXT("%f Acceptance moving toward: %s"), AcceptanceRadius, *(PlayerTank->GetName()));
		FVector PlayerLocation = PlayerTank->GetActorLocation();
		AITank->AimAtTank(PlayerLocation);
		AITank->Fire(); 
	}
	
}

