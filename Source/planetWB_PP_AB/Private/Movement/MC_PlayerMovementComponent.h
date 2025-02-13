// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MC_PlayerMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class UMC_PlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Blueprintcallable)
		void UpdateGravityDirection(const FVector& NewGravityDirection);
};
