// Created by Liu xijun

#pragma once

#include "CoreMinimal.h"
#include "WarriorEnumTypes.h"

/**
 * 
 */
class WARRIOR_API FWarriorCountDownAction : public FPendingLatentAction
{
public:
	FWarriorCountDownAction(float InTotalCountDownTime, float InUpdateInterval, float& InOutRemainingTime,
		EWarriorCountDownActionOutput& InCountDownOutput, FLatentActionInfo LatentInfo)
		: bNeedCancel(false), TotalCountDownTime(InTotalCountDownTime), UpdateInterval(InUpdateInterval),
		  OutRemainingTime(InOutRemainingTime), CountDownOutput(InCountDownOutput),
		  ExecutionFunction(LatentInfo.ExecutionFunction), OutputLink(LatentInfo.Linkage),
		  CallbackTarget(LatentInfo.CallbackTarget), ElapsedInterval(0.f), ElapsedTimeSinceStart(0.f)
	{
		
	}

	virtual void UpdateOperation(FLatentResponse& Response) override;

	void CancelAction();

private:

	bool bNeedCancel;
	float TotalCountDownTime;
	// 更新间隔
	float UpdateInterval;
	// 通知蓝图剩余时间
	float& OutRemainingTime;
	EWarriorCountDownActionOutput& CountDownOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;
};
