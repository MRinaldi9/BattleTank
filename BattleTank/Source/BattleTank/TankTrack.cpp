// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is throttling at %f"), *Name, Throttle);

	//Applying force to the tracks 
	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;

	//Force applied on the tracks location
	FVector ForcedLocation = GetComponentLocation();

	//Getting the root of the Tank and casting to Primitive component for applying the force
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForcedLocation);
}


