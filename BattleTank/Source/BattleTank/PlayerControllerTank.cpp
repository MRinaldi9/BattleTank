// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerTank.h"


void APlayerControllerTank::BeginPlay() 
{
	Super::BeginPlay();
	ATank* TankPossessed = GetControlledTank();
	UE_LOG(LogTemp,Warning,TEXT("%s"),*TankPossessed->GetName())
}

void APlayerControllerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* APlayerControllerTank::GetControlledTank() const
{
	///Cast to a type ATank and get the pawn possessed
	return Cast<ATank>(GetPawn());
}

void APlayerControllerTank::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

}




