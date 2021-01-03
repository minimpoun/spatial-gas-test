#include "Attributes.h"
#include "UnrealNetwork.h"
#include "GameplayEffectExtension.h"


void UAttributes::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}

void UAttributes::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAttributes, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributes, Resource, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributes, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UAttributes::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributes, Health, OldHealth);
}

void UAttributes::OnRep_Resource(const FGameplayAttributeData& OldResource)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributes, Resource, OldResource);
}

void UAttributes::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributes, MaxHealth, OldMaxHealth);
}

