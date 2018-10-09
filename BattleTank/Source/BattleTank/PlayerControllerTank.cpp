// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerTank.h"




ATank* APlayerControllerTank::GetControlledTank() const
{
	///Cast to a type ATank and get the pawn possessed
	return Cast<ATank>(GetPawn());
}




