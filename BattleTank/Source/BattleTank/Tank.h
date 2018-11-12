// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class UTankMovementComponent;
class ATankProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = GamePlay)
	void Fire();

	UPROPERTY(EditDefaultsOnly,Category = Setup)
	float LaunchSpeed = 4000.f; //TODO Find a right value



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<ATankProjectile> ProjectileBlueprint = nullptr;


public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
private:
	UTankBarrel* LocalBarrel = nullptr;

	UPROPERTY(EditDefaultsOnly,Category = Setup)
	float ReloadShooting = 4;

	float LastTimeReload = 0;
	
};
