// Fill out your copyright notice in the Description page of Project Settings.
#include "Buildings/A_TurnInResources.h"
#include "AC_InventoryComponent.generated.h"
#include "AC_PlayerStats.generated.h"
#include "GameFramework/Character.h"

// Sets default values
AA_TurnInResources::AA_TurnInResources()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ResourceValues.Add("Coal", 5);
	ResourceValues.Add("Iron", 10);
	ResourceValues.Add("Silver", 30);
	ResourceValues.Add("Gold", 50);
	ResourceValues.Add("Platinum", 75);

}

// Called when the game starts or when spawned
void AA_TurnInResources::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_TurnInResources::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA_TurnInResources::TurnInResources(UAC_InventoryComponent* PlayerInventory, UAC_PlayerStats* PlayerStats)
{
    if (!PlayerInventory || !PlayerStats) return;

    int32 EarnedMoney = 0;

    for (auto& Resource : ResourceValues)
    {
        //int32 Amount = PlayerInventory->GetResourceAmount(Resource.Key);
        //if (Amount > 0)
        {
            //EarnedMoney += Amount * Resource.Value;
            //PlayerInventory->RemoveResource(Resource.Key, Amount);
        }
    }

    //PlayerStats->AddMoney(EarnedMoney);

    //UE_LOG(LogTemp, Warning, TEXT("Turned in resources for $%d! Total money: $%d"), EarnedMoney, PlayerStats->GetMoney());
}

