#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Attributes.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropName)

UCLASS()
class UAttributes : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAttributes, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAttributes, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Resource", ReplicatedUsing = OnRep_Resource)
	FGameplayAttributeData Resource;
	ATTRIBUTE_ACCESSORS(UAttributes, Resource);

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;

protected:
	
	virtual void GetLifetimeReplicatedProps( TArray<class FLifetimeProperty> & OutLifetimeProps ) const override;

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_Resource(const FGameplayAttributeData& OldResource);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

};