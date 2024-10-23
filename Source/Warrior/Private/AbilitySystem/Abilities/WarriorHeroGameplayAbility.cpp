// Created by Liu xijun


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroPlayerController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedWarriorHeroCharacter.IsValid() ? CachedWarriorHeroCharacter.Get() : nullptr;
}

AWarriorHeroPlayerController* UWarriorHeroGameplayAbility::GetHeroPlayerControllerFromActorInfo()
{
	if (!CachedWarriorHeroPlayerController.IsValid())
	{
		CachedWarriorHeroPlayerController = Cast<AWarriorHeroPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedWarriorHeroPlayerController.IsValid() ? CachedWarriorHeroPlayerController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	if (const AWarriorHeroCharacter* WarriorHeroCharacter = GetHeroCharacterFromActorInfo())
	{
		return WarriorHeroCharacter->GetHeroCombatComponent();
	}
	return nullptr;
}
