// Copyrighted by Devoted Koi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "PlayerCharacter.generated.h"

class UAttributeSetBase;

UCLASS()
class PROJECT_C_API APlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		UAbilitySystemComponent* AbilitySystemComp;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		UAttributeSetBase* AttributeBaseComp;

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

	/* Health Attribute Functions */
	UFUNCTION()
		void OnHealthChanged(float Health, float MaxHealth);
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnHealthChanged"))
		void BP_OnhealthChanged(float Health, float Maxhealth);

	/* Mana Attribute Functions */
	UFUNCTION()
		void OnManaChanged(float Mana, float MaxMana);
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnManaChanged"))
		void BP_OnManaChanged(float Mana, float MaxMana);

	/* Strength Attribute Functions */
	UFUNCTION()
		void OnStrengthChanged(float Strength, float MaxStrength);
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnStrengthChanged"))
		void BP_OnStrengthChanged(float Strength, float MaxStrength);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "Die"))
		void BP_Die();

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		bool IsOtherHostile(APlayerCharacter* Other);
	
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void RefreshAbilities();

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipPrimaryAbility(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipSecondaryAbility(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipHeadSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipChestSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipArmsSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipLegsSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipSkillOneSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipSkillTwoSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipSkillThreeSlot(TSubclassOf<UGameplayAbility> Ability);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void EquipSkillFourSlot(TSubclassOf<UGameplayAbility> Ability);


	uint8 GetTeamID() const;
protected:
	bool bIsDead;
	uint8 TeamID;
	void AutoDetermineTeamIDbyControllerType();
	void Dead();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> PrimarySlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> SecondarySlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> HeadSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> ChestSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> ArmsSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> LegsSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> SkillOneSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> SkillTwoSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> SkillThreeSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		TSubclassOf<UGameplayAbility> SkillFourSlot;

};
