// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerTank.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API AAIControllerTank : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetAIControlledTank() const;
	

private:
	ATank* GetPlayerTank() const;
	
};
