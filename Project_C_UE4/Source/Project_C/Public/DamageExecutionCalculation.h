// Copyrighted by Devoted Koi

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "DamageExecutionCalculation.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT_C_API UDamageExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	/* Constructor */
	UDamageExecutionCalculation();

	// Must have these two variable to capture the Health in order to read/write
	UProperty* HealthProperty;
	FGameplayEffectAttributeCaptureDefinition HealthDef;


	void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;
};
