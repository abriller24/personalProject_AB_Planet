// Fill out your copyright notice in the Description page of Project Settings.
#include "Managers/AC_VoxelModifier.h"
#include "Camera/CameraComponent.h"
//#include "VoxelData/VoxelData.h"
//#include "VoxelUtilities/VoxelMaterialUtilities.h"
#include "GameFramework/Actor.h"
#include "AC_InventoryComponent.generated.h"
#include "Engine/Engine.h"

UAC_VoxelModifier::UAC_VoxelModifier()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_VoxelModifier::BeginPlay()
{
	Super::BeginPlay();

	// ...
	/*for (TActorIterator<AVoxelWorld> It(GetWorld()); It; ++It)
	{
		VoxelWorld = *It;
		break;
	}*/
}


// Called every frame
void UAC_VoxelModifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_VoxelModifier::PerformVoxelTrace()
{
	if (!GetOwner())
		return;

	TArray<UCameraComponent*> CameraComponents;
	GetOwner()->GetComponents<UCameraComponent>(CameraComponents);

	if (CameraComponents.Num() > 0)
	{
		UCameraComponent* CameraComp = CameraComponents[0];
		UE_LOG(LogTemp, Warning, TEXT("Found Camera: %s"), *CameraComp->GetName());

		FVector StartLocation = CameraComp->GetComponentLocation();
		FVector ForwardVector = CameraComp->GetForwardVector();
		FVector EndLocation = StartLocation + (ForwardVector * TraceDistance);

		FHitResult HitResult;
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(GetOwner());

		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);

		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Purple, false, 2.0f, 0, 1.0f);

		if (bHit) 
		{
			AActor* HitActor = HitResult.GetActor();
			if (HitActor && HitActor->IsA(TargetClass)) 
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitActor->GetName());
				FVector SpawnLocation = HitResult.ImpactPoint;
				float Radius = 10.0f;
				UE_LOG(LogTemp, Warning, TEXT("Spawn Voxel at: %s"), *SpawnLocation.ToString());
			}
		}
	}
}

void UAC_VoxelModifier::MineVoxel(FVector HitPosition)
{
	//if (!VoxelWorld) return;

	//FVoxelEditInterface EditInterface = VoxelWorld->GetData().GetEditInterface();

	// Convert world position to voxel position
	//FIntVector VoxelPosition = VoxelWorld->GlobalToLocal(HitPosition);

	// Remove the voxel
	//EditInterface.SetValue(VoxelPosition, 0);

	TArray<FName> PossibleResources = { "Coal", "Iron", "Gold", "Silver", "Platinum"};
	FName SelectedResource = PossibleResources[FMath::RandRange(0, PossibleResources.Num() - 1)];
	int32 Amount = FMath::RandRange(1, 5);

	/*ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter)
	{
		UAC_InventoryComponent* Inventory = OwnerCharacter->FindComponentByClass<UAC_InventoryComponent>();
		if (Inventory)
		{
			Inventory->AddResource(SelectedResource, Amount);
		}
	}*/
}

void UAC_VoxelModifier::AddVoxel(float Radius, FVector Location)
{
	/*if (!VoxelWorld) return;

	FVoxelEditInterface EditInterface = VoxelWorld->GetData().GetEditInterface();

	FIntVector VoxelPosition = VoxelWorld->GlobalToLocal(Location);

	EditInterface.SetValue(VoxelPosition, 1); 

	FVoxelMaterial Material;
	Material.SetSingleIndex(MaterialIndex);
	EditInterface.SetMaterial(VoxelPosition, Material);*/
}

