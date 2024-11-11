// Created by Liu xijun

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WarriorTypes/WarriorEnumTypes.h"
#include "WarriorGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AWarriorGameModeBase();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	EWarriorGameDifficulty CurrentGameDifficulty;

public:

	FORCEINLINE EWarriorGameDifficulty GetCurrentGameDifficulty() const { return CurrentGameDifficulty; } 
};
