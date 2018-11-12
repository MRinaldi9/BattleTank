// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankProjectile.h"
#include "TankBarrel.h"




// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("TankAimComponent"));
	TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("TankMovementComponent"));

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

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	LocalBarrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	bool bIsReloaded = (GetWorld()->GetTimeSeconds() - LastTimeReload) > ReloadShooting;

	if (!ProjectileBlueprint) { return; }

	if (LocalBarrel && bIsReloaded)
	{
		auto ProjectileInstance = GetWorld()->SpawnActor<ATankProjectile>(
			ProjectileBlueprint,
			LocalBarrel->GetSocketLocation(FName("EndBarrel")),
			LocalBarrel->GetSocketRotation(FName("EndBarrel")));

		ProjectileInstance->LaunchProjectile(LaunchSpeed);
		LastTimeReload = GetWorld()->GetTimeSeconds();
	}

}
