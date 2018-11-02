// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"

void UTankTurret::RotationTurret(float VelocityRotation)
{
	auto ClampedRotationSpeed = FMath::Clamp(VelocityRotation, -5.f, 5.f);

	auto RotationChange = ClampedRotationSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
