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
	//Direction of Crosshair
	FVector OutWorldCameraDirection;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	//Position of crosshair in screen(Pixel coordinate)
	auto ScreenLocationCrossHair = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//Return the direction of the crosshair in the world 3D
	if (GetLookDirection(ScreenLocationCrossHair, OutWorldCameraDirection))
	{
		//From the GetLookDirection we can pass the direction vector and take the location of the linetrace Hit
		GetLookVectorHitLocation(OutWorldCameraDirection, OutHitLocation);
	}

	return true;
}

bool APlayerControllerTank::GetLookDirection(FVector2D ObjScreenLocation,FVector& LookDirection ) const
{
	//Parameters to be discarded because is the camera position
	FVector OutWorldCameraLocation = FVector::ZeroVector; 
	//"De-Projection" from Crosshair position in screen to World 3D(Deproject return false only if he don't know how to determine the position of the object)
	return DeprojectScreenPositionToWorld(ObjScreenLocation.X, ObjScreenLocation.Y, OutWorldCameraLocation, LookDirection);
}

bool APlayerControllerTank::GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToCompactString())
		return true;
	}
	HitLocation = FVector::ZeroVector;
	return false;
}




