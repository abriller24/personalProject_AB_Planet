// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/AC_InventoryComponent.h"

// Sets default values for this component's properties
UAC_InventoryComponent::UAC_InventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// Called when the game starts
void UAC_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_InventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_InventoryComponent::AddResource(FName ResourceName, int32 Amount)
{
	if (Amount <= 0) return;

	// Check if the resource already exists in inventory
	for (FResourceItem& Item : Inventory)
	{
		if (Item.ResourceName == ResourceName)
		{
			Item.Amount += Amount;
			return;
		}
	}

	// If not, add a new entry
	Inventory.Add(FResourceItem(ResourceName, Amount));
}

int32 UAC_InventoryComponent::GetResourceAmount(FName ResourceName) const
{
	for (const FResourceItem& Item : Inventory)
	{
		if (Item.ResourceName == ResourceName)
		{
			return Item.Amount;
		}
	}
	return 0; 
}
