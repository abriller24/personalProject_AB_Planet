// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/APlanetSpawnerManager.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"


// Sets default values
AAPlanetSpawnerManager::AAPlanetSpawnerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlanetLevels = { FName(TEXT("Planet_01")), FName(TEXT("Planet_02")) };
}

// Called when the game starts or when spawned
void AAPlanetSpawnerManager::BeginPlay()
{
	Super::BeginPlay();
	
	BP_ThirdPersonCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

// Called every frame
void AAPlanetSpawnerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!BP_ThirdPersonCharacter)
		return;

	if (BP_ThirdPersonCharacter)
		ManageLevelStreaming();

}

void AAPlanetSpawnerManager::ManageLevelStreaming()
{
	if (!BP_ThirdPersonCharacter)
		return;

	FVector PlayerLoc = BP_ThirdPersonCharacter->GetActorLocation();

	for (FName PlanetLevelName : PlanetLevels) 
	{
		FVector PlanetLocation = GetPlanetLocationByLevelName(PlanetLevelName);

		float Distance = FVector::Dist(PlayerLoc, PlanetLocation);
		float ThreshholdDistance = 1000.0f;

		if (Distance < ThreshholdDistance) 
		{
			LoadPlanetLevel(PlanetLevelName);
		}
		else
		{
			UnloadPlanetLevel(PlanetLevelName);
		}
	}
}

void AAPlanetSpawnerManager::LoadPlanetLevel(FName LevelName)
{
	ULevelStreaming* StreamingLevel = UGameplayStatics::GetStreamingLevel(GetWorld(), LevelName);
	if (StreamingLevel && StreamingLevel->IsLevelLoaded())
		return;

	UGameplayStatics::LoadStreamLevel(GetWorld(), LevelName, true, true, FLatentActionInfo());
}

void AAPlanetSpawnerManager::UnloadPlanetLevel(FName LevelName)
{
	ULevelStreaming* StreamingLevel = UGameplayStatics::GetStreamingLevel(GetWorld(), LevelName);
	if (StreamingLevel && StreamingLevel->IsLevelLoaded())
	{
		UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelName, FLatentActionInfo(), true);
	}
}

FVector AAPlanetSpawnerManager::GetPlanetLocationByLevelName(FName LevelName) 
{
	AActor* PlanetActor = FindPlanetActorByLevelName(LevelName);
	if (PlanetActor)
		return PlanetActor->GetActorLocation();

	return FVector(0.0f, 0.0f, 0.0f);

}

AActor* AAPlanetSpawnerManager::FindPlanetActorByLevelName(FName LevelName)
{
	TArray<AActor*> FoundActors;
	return nullptr;
}

