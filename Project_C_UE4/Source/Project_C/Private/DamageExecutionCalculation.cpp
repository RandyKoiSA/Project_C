// Copyrighted by Devoted Koi


#include "DamageExecutionCalculation.h"
#include "AttributeSetBase.h"

struct DamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackDamage)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)
	DamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, AttackDamage, Source, true)
			DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, Armor, Target, true)
	}
};

static DamageStatics& GetDamageStatics()
{
	static DamageStatics DamageStaticsVar;
	return DamageStaticsVar;
}

UDamageExecutionCalculation::UDamageExecutionCalculation()
{
	HealthProperty = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health));
	HealthDef = FGameplayEffectAttributeCaptureDefinition(HealthProperty, EGameplayEffectAttributeCaptureSource::Target, true);

	/* Attribute to capture that are relevant to the calculation */
	RelevantAttributesToCapture.Add(HealthDef);

	RelevantAttributesToCapture.Add(GetDamageStatics().AttackDamageDef);
	RelevantAttributesToCapture.Add(GetDamageStatics().ArmorDef);

}

void UDamageExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	float AttackDamageMagnitude = 0.0f;

	// This is how we get the AttackDamage Attribute in AttributeSetBase
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageStatics().AttackDamageDef, FAggregatorEvaluateParameters(), AttackDamageMagnitude);
	
	// This is how we get the Armor Attribute in AttributeSetBase
	float ArmorMagnitude = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageStatics().ArmorDef, FAggregatorEvaluateParameters(), ArmorMagnitude);

	// This is where we do out calculation
	float finalDamage = FMath::Clamp(AttackDamageMagnitude - ArmorMagnitude, 0.0f, AttackDamageMagnitude);
	UE_LOG(LogTemp, Warning, TEXT("Dealing %f Damage to Target!"), finalDamage);
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(HealthProperty, EGameplayModOp::Additive, -finalDamage));
}
