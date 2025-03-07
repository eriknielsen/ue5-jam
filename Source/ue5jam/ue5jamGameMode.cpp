// Copyright Epic Games, Inc. All Rights Reserved.

#include "ue5jamGameMode.h"
#include "ue5jamPlayerController.h"
#include "ue5jamCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aue5jamGameMode::Aue5jamGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = Aue5jamPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}