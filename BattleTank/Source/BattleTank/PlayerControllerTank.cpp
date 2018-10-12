// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerTank.h"


void APlayerControllerTank::BeginPlay()
{
	Super::BeginPlay();
	ATank* TankPossessed = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *TankPossessed->GetName())
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

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *OutHitLocation.ToString())
	}


}

bool APlayerControllerTank::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	FVector OutWorldDirection;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	//Position of crosshair in screen(Pixel coordinate)
	auto ScreenLocationCrossHair = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	if (GetLookDirection(ScreenLocationCrossHair, OutWorldDirection))
	{
		UE_LOG(LogTemp,Warning,TEXT("I'm looking at: %s"),*OutWorldDirection.ToString())
	}

	return true;
}

bool APlayerControllerTank::GetLookDirection(FVector2D ObjScreenLocation,FVector& LookDirection ) const
{
	//Parameters to be discarded because is the camera position
	FVector OutWorldLocation = FVector::ZeroVector; 
	//"De-Projection" from Crosshair position in screen to World 3D
	return DeprojectScreenPositionToWorld(ObjScreenLocation.X, ObjScreenLocation.Y, OutWorldLocation, LookDirection);
}




