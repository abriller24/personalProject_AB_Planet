// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/AC_PlayerStats.h"

// Sets default values for this component's properties
UAC_PlayerStats::UAC_PlayerStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	Money = 0;
}


// Called when the game starts
void UAC_PlayerStats::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_PlayerStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_PlayerStats::AddMoney(int32 Amount)
{
	if (Amount > 0)
	{
		Money += Amount;
		UE_LOG(LogTemp, Warning, TEXT("Added Money: %d | Total: %d"), Amount, Money);
	}
}

int32 UAC_PlayerStats::GetMoney() const
{
	return Money;
}


