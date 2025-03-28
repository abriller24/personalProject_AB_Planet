// Fill out your copyright notice in the Description page of Project Settings.


#include "A_ShipActor.h"

// Sets default values
AA_ShipActor::AA_ShipActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AA_ShipActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_ShipActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



