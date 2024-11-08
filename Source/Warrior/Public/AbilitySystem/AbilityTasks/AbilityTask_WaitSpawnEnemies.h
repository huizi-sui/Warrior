// Created by Liu xijun

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_WaitSpawnEnemies.generated.h"

class AWarriorEnemyCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitSpawnEnemiesDelegate, const TArray<AWarriorEnemyCharacter*>&, SpawnedEnemies);

/**
 * 
 */
UCLASS()
class WARRIOR_API UAbilityTask_WaitSpawnEnemies : public UAbilityTask
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Warrior|AbilityTasks", meta = (DisplayName = "Wait Gameplay Event And Spawn Enemies",
		HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true",
		NumToSpawn = "1", RandomSpawnRadius = "200")) // Default value
	static UAbilityTask_WaitSpawnEnemies* WaitSpawnEnemies(UGameplayAbility* OwningAbility,
		FGameplayTag EventTag,
		TSoftClassPtr<AWarriorEnemyCharacter> SoftEnemyClassToSpawn,
		int32 NumToSpawn,
		const FVector& SpawnOrigin,
		float RandomSpawnRadius);

	//~ Begin UGameplayTask Interface
	virtual void Activate() override;
	virtual void OnDestroy(bool bInOwnerFinished) override;
	//~ End UGameplayTask Interface

	UPROPERTY(BlueprintAssignable)
	FWaitSpawnEnemiesDelegate OnSpawnFinished;

	UPROPERTY(BlueprintAssignable)
	FWaitSpawnEnemiesDelegate DidNotSpawn;

private:
	FGameplayTag CachedEventTag;
	TSoftClassPtr<AWarriorEnemyCharacter> CachedSoftEnemyClassToSpawn;
	int32 CachedSpawnNum;
	FVector CachedSpawnOrigin;
	float CachedRandomSpawnRadius;
	FDelegateHandle DelegateHandle;

	void OnGameplayEventReceived(const FGameplayEventData* InPayload);
	void OnEnemyClassLoaded();
};