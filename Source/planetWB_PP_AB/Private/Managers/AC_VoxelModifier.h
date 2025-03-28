// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "VoxelWorld.h"
#include "AC_VoxelModifier.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UAC_VoxelModifier : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_VoxelModifier();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void PerformVoxelTrace();

private:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float TraceDistance = 2500.0f;
		
	//UPROPERTY(EditAnywhere, Category = "Voxel")
	//AVoxelWorld* VoxelWorld;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	TSubclassOf<AActor> TargetClass;

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void MineVoxel(FVector HitPosition);

	UFUNCTION(BlueprintCallable, Category = "Voxel")
	void AddVoxel(float Radius, FVector Location);

};
