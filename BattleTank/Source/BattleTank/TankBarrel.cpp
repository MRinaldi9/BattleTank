// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

void UTankBarrel::Elevation(float RelativeSpeed)
{
	float ClampedSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	//Movements of the right amount, of the barrel, on this frame
	auto ElevationChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ClampedNewElevation = FMath::Clamp(RawNewElevation, MinDegrees, MaxDegrees);


	SetRelativeRotation(FRotator(ClampedNewElevation, 0, 0));
}

