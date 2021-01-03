#include "STGameInstance.h"
#include "AbilitySystemGlobals.h"

void USTGameInstance::Init()
{
	Super::Init();

	UAbilitySystemGlobals& ASG = UAbilitySystemGlobals::Get();
	if (!ASG.IsAbilitySystemGlobalsInitialized())
	{
		ASG.InitGlobalData();
	}
}

