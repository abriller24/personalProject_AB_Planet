// Copyright Epic Games, Inc. All Rights Reserved.

#include "planetWB_PP_ABGameMode.h"
#include "planetWB_PP_ABCharacter.h"
#include "UObject/ConstructorHelpers.h"

AplanetWB_PP_ABGameMode::AplanetWB_PP_ABGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
