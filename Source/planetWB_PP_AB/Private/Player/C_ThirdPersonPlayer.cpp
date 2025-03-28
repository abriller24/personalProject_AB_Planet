#include "Player/C_ThirdPersonPlayer.h"

// Sets default values
AC_ThirdPersonPlayer::AC_ThirdPersonPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_ThirdPersonPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AC_ThirdPersonPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AC_ThirdPersonPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}



