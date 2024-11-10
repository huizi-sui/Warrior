// Created by Liu xijun


#include "AbilitySystem/Abilities/HeroGameplayAbility_PickUpStones.h"

#include "Characters/WarriorHeroCharacter.h"
#include "Components/UI/HeroUIComponent.h"
#include "Items/PickUps/WarriorStoneBase.h"
#include "Kismet/KismetSystemLibrary.h"

void UHeroGameplayAbility_PickUpStones::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	GetHeroUIComponentFromActorInfo()->OnStoneInteracted.Broadcast(true);
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UHeroGameplayAbility_PickUpStones::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	GetHeroUIComponentFromActorInfo()->OnStoneInteracted.Broadcast(false);
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UHeroGameplayAbility_PickUpStones::CollectStones()
{
	CollectedStones.Empty();
	const AWarriorHeroCharacter* HeroCharacter = GetHeroCharacterFromActorInfo();
	TArray<FHitResult> TraceHits;
	
	UKismetSystemLibrary::BoxTraceMultiForObjects(
		HeroCharacter,
		HeroCharacter->GetActorLocation(),
		HeroCharacter->GetActorLocation() - HeroCharacter->GetActorUpVector() * BoxTraceDistance,
		TraceBoxSize * 0.5f,
		(-HeroCharacter->GetActorUpVector()).ToOrientationRotator(),
		StoneTraceChannel,
		false,
		TArray<AActor*>(),
		bDrawDebugShape ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
		TraceHits,
		true);
	
	for (const FHitResult& TraceHit : TraceHits)
	{
		if (AWarriorStoneBase* FoundStone = Cast<AWarriorStoneBase>(TraceHit.GetActor()))
		{
			CollectedStones.AddUnique(FoundStone);
		}
	}

	if (CollectedStones.IsEmpty())
	{
		CancelAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true);
	}
}

void UHeroGameplayAbility_PickUpStones::ConsumeStones()
{
	UWarriorAbilitySystemComponent* AbilitySystemComponent = GetWarriorAbilitySystemComponentFromActorInfo();
	const int32 ApplyLevel = GetAbilityLevel();
	for (AWarriorStoneBase* CollectedStone : CollectedStones)
	{
		CollectedStone->Consume(AbilitySystemComponent, ApplyLevel);
	}
}
