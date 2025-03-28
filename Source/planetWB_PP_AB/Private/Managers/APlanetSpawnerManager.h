// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APlanetSpawnerManager.generated.h"

UCLASS()
class AAPlanetSpawnerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAPlanetSpawnerManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector GetPlanetLocationByLevelName(FName LevelName);
	AActor* FindPlanetActorByLevelName(FName LevelName);

public:
	UPROPERTY()
	ACharacter* BP_ThirdPersonCharacter;
	TArray<FName> PlanetLevels;
	float MaxDistanceToLoad = 10000.0f;
	
	UFUNCTION()
	void ManageLevelStreaming();
	void LoadPlanetLevel(FName LevelName);
	void UnloadPlanetLevel(FName LevelName);
};
