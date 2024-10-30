// Created by Liu xijun

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "WarriorHeroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:

	AWarriorHeroPlayerController();

	//~ Begin IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End IGenericTeamAgentInterface

private:
	FGenericTeamId HeroTeamID;
};
