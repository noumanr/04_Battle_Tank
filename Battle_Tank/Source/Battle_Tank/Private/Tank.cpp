// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"

//#include "Uobject/ConstructorHelpers.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

/*

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Body"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TankMesh(TEXT("/Game/Meshes/Tank/tank_fbx_Body.tank_fbx_Body"));
	if (TankMesh.Object)
	{
		Body->SetStaticMesh(TankMesh.Object);
		UE_LOG(LogTemp, Warning, TEXT("it Worked"));
	}

	Barrel = CreateDefaultSubobject<UTankBarrel>(TEXT("Tank Barrel"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelMesh(TEXT("/Game/Meshes/Tank/tank_fbx_Barrel.tank_fbx_Barrel"));
	if (TankMesh.Object)
	{
		Barrel->SetStaticMesh(BarrelMesh.Object);
		UE_LOG(LogTemp, Warning, TEXT("it Worked"));
	}*/
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAtTank(FVector HitLocation)
{
	TankAimingComponent->AimAtTank(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}
void ATank::SetTurretRefernce(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretRefernce(TurretToSet);

}
void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > FireDelay ;

	if (Barrel && isReloaded) {
	

	FVector ProjectileLocation = Barrel->GetSocketLocation(FName("FireSocket"));
	FRotator ProjectileRotation = Barrel->GetSocketRotation(FName("FireSocket"));

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, ProjectileLocation, ProjectileRotation);

	Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
	}
}