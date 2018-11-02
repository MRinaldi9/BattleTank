// Fill out your copyright notice in the Description page of Project Settings.

#include "AIControllerTank.h"
#include "Tank.h"
#include "Engine/World.h"




void AAIControllerTank::BeginPlay()
{
	Super::BeginPlay();

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

