// Copyrighted by Devoted Koi

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/* Create a broadcast channel to use*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangeDelegate, float, Attr, float, MaxAttr);

UCLASS()
class PROJECT_C_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()


public:
	UAttributeSetBase();

	/*
	 Health Attribute
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData MaxHealth;
	/*
	Mana Attribute
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData MaxMana;
	/*
	Strength Attribute
	(Have no use yet)
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData MaxStrength;

	/*
	Armor Attribute
	Reduce damage output
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData Armor;
	/*
	Attack Attribute
	Increase attack damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
		FGameplayAttributeData AttackDamage;

	/* Override Function PostGameplayEffectExecute */
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	/* Override Function PreGameplayEffectExecute */
	bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	/* Broadcast Channels */
	FOnAttributeChangeDelegate OnHealthChange;
	FOnAttributeChangeDelegate OnManaChange;
	FOnAttributeChangeDelegate OnStrengthChange;
	FOnAttributeChangeDelegate OnDefenseChange;

};