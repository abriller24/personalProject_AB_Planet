// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement/MC_PlayerMovementComponent.h"

void UMC_PlayerMovementComponent::UpdateGravityDirection(const FVector& NewGravityDirection)
{
	SetGravityDirection(NewGravityDirection);
}
