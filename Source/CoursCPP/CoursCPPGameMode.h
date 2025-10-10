// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoursCPPGameMode.generated.h"

/**
 *  Simple GameMode for a first person game
 */
UCLASS(abstract)
class COURSCPP_API ACoursCPPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACoursCPPGameMode();
private: 
	void Test(float a);
};



