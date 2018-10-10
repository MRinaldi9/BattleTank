// Fill out your copyright notice in the Description page of Project Settings.

#include "AIControllerTank.h"


void AAIControllerTank::BeginPlay()
{
	Super::BeginPlay();

	ATank* AITankControlled = GetAIControlledTank();
	UE_LOG(LogTemp,Warning,TEXT("%s"),*(AITankControlled->GetName()))
}

ATank* AAIControllerTank::GetAIControlledTank()
{
	return Cast<ATank>(GetPawn());
}

