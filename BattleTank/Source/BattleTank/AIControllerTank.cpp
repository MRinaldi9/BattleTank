// Fill out your copyright notice in the Description page of Project Settings.

#include "AIControllerTank.h"


void AAIControllerTank::BeginPlay()
{
	Super::BeginPlay();

	auto AITankControlled = GetAIControlledTank();
	auto PlayerTankControlled = GetPlayerTank();
	UE_LOG(LogTemp, Warning, TEXT("I'm aiming at: %s"), *(GetPlayerTank()->GetName()))
}

void AAIControllerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetAIControlledTank())
	{
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	}
}

ATank* AAIControllerTank::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* AAIControllerTank::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

