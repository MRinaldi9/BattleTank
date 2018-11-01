// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"



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
	TArray<AActor*> Actors;

	if (UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutSuggestedVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.5f,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		Actors,
		true
	))
	{
		auto AimDirection = OutSuggestedVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelDirection = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	//Difference from actual position and rotation of the barrel
	auto DeltaRotator = AimAsRotator - BarrelDirection;
	UE_LOG(LogTemp, Warning, TEXT("Tank is: %s AimAsRotator is %s"), *DeltaRotator.ToString())

	Barrel->Elevetion(5);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

