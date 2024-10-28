﻿
#pragma once

#include "WarriorEnumTypes.generated.h"

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EWarriorValidType : uint8
{
	Valid,
	InValid
};

UENUM()
enum class EWarriorSuccessType : uint8
{
	Successful,
	Failed
};

