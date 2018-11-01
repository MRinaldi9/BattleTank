// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerTank.generated.h"

class ATank;

/**
 *
 */
UCLASS()
class BATTLETANK_API APlayerControllerTank : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;


private:
	void AimTowardsCrosshair();
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.23111f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ObjScreenLocation,FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector ScreenLocation,FVector& HitLocation) const;


};
