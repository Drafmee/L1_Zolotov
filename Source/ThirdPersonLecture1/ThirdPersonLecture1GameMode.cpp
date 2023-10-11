// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonLecture1GameMode.h"
#include "ThirdPersonLecture1Character.h"
#include "UObject/ConstructorHelpers.h"

AThirdPersonLecture1GameMode::AThirdPersonLecture1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
