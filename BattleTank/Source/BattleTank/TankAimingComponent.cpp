// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"





// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutSuggestedVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("EndBarrel"));
	//Return true when there is a solution for the method, else when there isn't a solution or the solution is blocked then return false
	bool bIsValidSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutSuggestedVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bIsValidSolution)
	{
		auto AimDirection = OutSuggestedVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: AimComponent found"), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: AimComponent not found"), Time);
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelDirection = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	//Difference from actual position and rotation of the barrel
	auto DeltaRotator = AimAsRotator - BarrelDirection;

	Barrel->Elevation(DeltaRotator.Pitch);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

