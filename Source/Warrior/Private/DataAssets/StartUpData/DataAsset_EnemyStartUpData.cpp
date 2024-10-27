// Created by Liu xijun


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorEnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GivenToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GivenToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const TSubclassOf<UWarriorEnemyGameplayAbility>& AbilityClass : EnemyCombatAbility)
	{
		if (!AbilityClass) continue;

		FGameplayAbilitySpec AbilitySpec(AbilityClass, ApplyLevel);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
