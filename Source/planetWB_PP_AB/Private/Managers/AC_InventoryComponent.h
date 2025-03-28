// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FResourceItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ResourceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;

	FResourceItem() : ResourceName(NAME_None), Amount(0) {}
	FResourceItem(FName Name, int32 Qty) : ResourceName(Name), Amount(Qty) {}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UAC_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_InventoryComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddResource(FName ResourceName, int32 Amount);

	UFUNCTION(BlueprintCallable)
	int32 GetResourceAmount(FName ResourceName) const;
private:
	UPROPERTY()
	TArray<FResourceItem> Inventory;
		
};
