// Created by Liu xijun


#include "AnimInstances/WarriorBaseAnimInstance.h"

#include "WarriorFunctionLibrary.h"

bool UWarriorBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UWarriorFunctionLibrary::NativeDoesActorHasTag(OwningPawn, TagToCheck);
	}
	return false;
}
