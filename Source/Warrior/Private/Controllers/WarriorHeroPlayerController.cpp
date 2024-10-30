// Created by Liu xijun


#include "Controllers/WarriorHeroPlayerController.h"

AWarriorHeroPlayerController::AWarriorHeroPlayerController()
{
	HeroTeamID = FGenericTeamId(0);
}

FGenericTeamId AWarriorHeroPlayerController::GetGenericTeamId() const
{
	return HeroTeamID;
}
