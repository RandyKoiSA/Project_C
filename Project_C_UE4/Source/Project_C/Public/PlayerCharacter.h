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


	UFUNCTION(Category = "CharacterBase")
		void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire); /* Deprecated */

	UFUNCTION(Category = "CharacterBase")
		void AcquireAbilityWithHandle(TSubclassOf<UGameplayAbility> AbilityToAcquire, FGameplayAbilitySpecHandle& slothandle);

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

	/* Death Function*/
	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "Die"))
		void BP_Die();

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		bool IsOtherHostile(APlayerCharacter* Other);
	
	/* Equipment Functions*/
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void RefreshAbilities();	/* Deprecated */

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

	/* Add/Remove Gameplay Tags*/
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void AddGameplayTag(FGameplayTag& TagToAdd);
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
		void RemoveGameplayTag(FGameplayTag& TagToRemove);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
		FGameplayTag FullHealthTag;

protected:
	bool bIsDead;
	uint8 TeamID;
	void AutoDetermineTeamIDbyControllerType();
	void Dead();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> PrimarySlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle PrimaryAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> SecondarySlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle SecondaryAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> HeadSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle HeadAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> ChestSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle ChestAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> ArmsSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle ArmsAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> LegsSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle LegsAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> SkillOneSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle SkillOneAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> SkillTwoSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle SkillTwoAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> SkillThreeSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle SkillThreeAbilityHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSubclassOf<UGameplayAbility> SkillFourSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		FGameplayAbilitySpecHandle SkillFourAbilityHandle;
};
