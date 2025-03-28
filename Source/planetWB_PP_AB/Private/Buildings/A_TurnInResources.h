// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_TurnInResources.generated.h"

class UAC_InventoryComponent;
class UAC_PlayerStats;

UCLASS()
class AA_TurnInResources : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_TurnInResources();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void TurnInResources(UAC_InventoryComponent* PlayerInventory, UAC_PlayerStats* PlayerStats);

private:
	UPROPERTY(EditAnywhere, Category = "Turn-In")
	TMap<FName, int32> ResourceValues; 
};
