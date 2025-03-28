// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_ThirdPersonPlayer.generated.h"

UCLASS()
class AC_ThirdPersonPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_ThirdPersonPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* AddVoxel;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* RemoveVoxel;
};
