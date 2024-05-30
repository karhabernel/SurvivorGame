// Copyright Epic Games, Inc. All Rights Reserved.

#include "SurvivorGameGameMode.h"
#include "SurvivorGamePlayerController.h"
#include "SurvivorGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASurvivorGameGameMode::ASurvivorGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASurvivorGamePlayerController::StaticClass();

	//Todo. 시작 플레이어 캐릭터 바꾸기
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Player/BP_Player"));
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