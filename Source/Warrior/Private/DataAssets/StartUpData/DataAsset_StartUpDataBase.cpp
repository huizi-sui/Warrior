// Created by Liu xijun

#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"



void UDataAsset_StartUpDataBase::GivenToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
	{
		if (!EffectClass) continue;

		const UGameplayEffect* EffectCDO = EffectClass.GetDefaultObject();
		
		InASCToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext());
	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		// 如果能力无效
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability, ApplyLevel);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
