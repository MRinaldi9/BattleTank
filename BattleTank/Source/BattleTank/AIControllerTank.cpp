// Fill out your copyright notice in the Description page of Project Settings.

#include "AIControllerTank.h"
#include "Tank.h"
#include "Engine/World.h"




void AAIControllerTank::BeginPlay()
{
	Super::BeginPlay();
	AITank = Cast<ATank>(GetPawn());
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	PlayerTank = Cast<ATank>(PlayerPawn);
}

void AAIControllerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!AITank && !PlayerTank) { return; }

	AITank->AimAt(PlayerTank->GetActorLocation());
	AITank->Fire();
	

}

