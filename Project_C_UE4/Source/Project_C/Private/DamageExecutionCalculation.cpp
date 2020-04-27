// Copyrighted by Devoted Koi


#include "DamageExecutionCalculation.h"
#include "AttributeSetBase.h"

struct DamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackDamage)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)
	DECLARE_ATTRIBUTE_CAPTUREDEF(Strength)
	DamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, AttackDamage, Source, true)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, Armor, Target, true)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAttributeSetBase, Strength, Source, true)
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
	RelevantAttributesToCapture.Add(GetDamageStatics().StrengthDef);

}

void UDamageExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	float AttackDamageMagnitude = 0.0f;

	// This is how we get the AttackDamage Attribute in AttributeSetBase
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageStatics().AttackDamageDef, FAggregatorEvaluateParameters(), AttackDamageMagnitude);
	
	// This is how we get the Armor Attribute in AttributeSetBase
	float ArmorMagnitude = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageStatics().ArmorDef, FAggregatorEvaluateParameters(), ArmorMagnitude);

	// This is how we get the Strength Attribute in AttributeSetBase
	float StrengthMagnitude = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageStatics().StrengthDef, FAggregatorEvaluateParameters(), StrengthMagnitude);

	// This is where we do out calculation
	//float finalDamage = FMath::Clamp(AttackDamageMagnitude - ArmorMagnitude, 0.0f, AttackDamageMagnitude);
	float DamageMultiplier = (AttackDamageMagnitude + (FMath::Pow(StrengthMagnitude, 0.8))) / (AttackDamageMagnitude + ArmorMagnitude);
	float finalDamage = DamageMultiplier * AttackDamageMagnitude;

	UE_LOG(LogTemp, Warning, TEXT("Initial Attack Damage %f"), AttackDamageMagnitude);
	UE_LOG(LogTemp, Warning, TEXT("Armor %f"), ArmorMagnitude);
	UE_LOG(LogTemp, Warning, TEXT("Strength %f"), StrengthMagnitude);
	UE_LOG(LogTemp, Warning, TEXT("Damage Multiplier %f"), DamageMultiplier);
	UE_LOG(LogTemp, Warning, TEXT("Final Damage Output %f"), finalDamage);
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(HealthProperty, EGameplayModOp::Additive, -finalDamage));
}
