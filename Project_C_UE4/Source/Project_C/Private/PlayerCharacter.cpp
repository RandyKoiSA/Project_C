// Copyrighted by Devoted Koi


#include "PlayerCharacter.h"
#include "AttributeSetBase.h"
#include "AIController.h"
#include "GameFramework//PlayerController.h"
#include "BrainComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	AttributeBaseComp = CreateDefaultSubobject<UAttributeSetBase> ("AttributeSetBaseComp");
	bIsDead = false;
	TeamID = 255;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	// Have the function OnHealthChange subscribe to the broadcast of OnhealthChange in the AttributeBaseComponent
	AttributeBaseComp->OnHealthChange.AddDynamic(this, &APlayerCharacter::OnHealthChanged);
	AttributeBaseComp->OnManaChange.AddDynamic(this, &APlayerCharacter::OnManaChanged);
	AddGameplayTag(FullHealthTag);
	AutoDetermineTeamIDbyControllerType();

	/* If default abilities were selected in the blueprint we can set it to the ability slots right away. */
	RefreshAbilities();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* APlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void APlayerCharacter::AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToAcquire)
		{
			FGameplayAbilitySpecDef SpecDef = FGameplayAbilitySpecDef();
			SpecDef.Ability = AbilityToAcquire;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SpecDef, 1);
			AbilitySystemComp->GiveAbility(AbilitySpec);
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

void APlayerCharacter::AcquireAbilityWithHandle(TSubclassOf<UGameplayAbility> AbilityToAcquire, FGameplayAbilitySpecHandle& slothandle)
{
	// Make sure Ability System Component is valid
	if (AbilitySystemComp)
	{
		// Remove ability in previous slot if any
		if (slothandle.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Existing Ability was in this slot, removing it now !"))
			AbilitySystemComp->ClearAbility(slothandle);
		}
		// If we have authority and the ability is valid, we then set the ability onto our slot
		if (HasAuthority() && AbilityToAcquire)
		{
			FGameplayAbilitySpecDef SpecDef = FGameplayAbilitySpecDef();
			SpecDef.Ability = AbilityToAcquire;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SpecDef, 1);
			// set new ability to slot handle
			slothandle = AbilitySystemComp->GiveAbility(AbilitySpec);
			UE_LOG(LogTemp, Warning, TEXT("New Ability was set onto the slot handle!"));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

void APlayerCharacter::OnHealthChanged(float Health, float MaxHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("I've been hit."));
	if (Health <= 0.0f && !bIsDead)
	{
		bIsDead = true;
		Dead();
		BP_Die();
	}
	BP_OnhealthChanged(Health, MaxHealth);
}

void APlayerCharacter::OnManaChanged(float Mana, float MaxMana)
{
	BP_OnManaChanged(Mana, MaxMana);
}

/* Checks if the target interacting is hostile */
bool APlayerCharacter::IsOtherHostile(APlayerCharacter* Other)
{
	return TeamID != Other->GetTeamID();
}

/* Remove all abilities in the component and add all the skills that is being currently equiped. */
void APlayerCharacter::RefreshAbilities()
{
	AbilitySystemComp->ClearAllAbilities();
	if (PrimarySlot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Primary Slot Available, Now equiped!"));
		AcquireAbility(PrimarySlot);
	}
	if (SecondarySlot)
	{
		AcquireAbility(SecondarySlot);
	}
	if (HeadSlot)
	{
		AcquireAbility(HeadSlot);
	}
	if (ChestSlot)
	{
		AcquireAbility(ChestSlot);
	}
	if (ArmsSlot)
	{
		AcquireAbility(ArmsSlot);
	}
	if (LegsSlot)
	{
		AcquireAbility(LegsSlot);
	}
	if (SkillOneSlot)
	{
		AcquireAbility(SkillOneSlot);
	}
	if (SkillTwoSlot)
	{
		AcquireAbility(SkillTwoSlot);
	}
	if (SkillThreeSlot)
	{
		AcquireAbility(SkillThreeSlot);
	}
	if (SkillFourSlot)
	{
		AcquireAbility(SkillFourSlot);
	}
}

void APlayerCharacter::EquipPrimaryAbility(TSubclassOf<UGameplayAbility> Ability)
{
	UE_LOG(LogTemp, Warning, TEXT("EquipingPrimaryAbility"));
	this->PrimarySlot = Ability;
	AcquireAbilityWithHandle(this->PrimarySlot, PrimaryAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipSecondaryAbility(TSubclassOf<UGameplayAbility> Ability)
{
	this->SecondarySlot = Ability;
	AcquireAbilityWithHandle(this->SecondarySlot, SecondaryAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipHeadSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->HeadSlot = Ability;
	AcquireAbilityWithHandle(this->HeadSlot, HeadAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipChestSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->ChestSlot = Ability;
	AcquireAbilityWithHandle(this->ChestSlot, ChestAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipArmsSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->ArmsSlot = Ability;
	AcquireAbilityWithHandle(this->ArmsSlot, ArmsAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipLegsSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->LegsSlot = Ability;
	AcquireAbilityWithHandle(this->LegsSlot, LegsAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipSkillOneSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillOneSlot = Ability;
	AcquireAbilityWithHandle(this->SkillOneSlot, SkillOneAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipSkillTwoSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillTwoSlot = Ability;
	AcquireAbilityWithHandle(this->SkillTwoSlot, SkillTwoAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipSkillThreeSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillThreeSlot = Ability;
	AcquireAbilityWithHandle(this->SkillThreeSlot, SkillThreeAbilityHandle);
	//RefreshAbilities();
}

void APlayerCharacter::EquipSkillFourSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillFourSlot = Ability;
	AcquireAbilityWithHandle(this->SkillFourSlot, SkillFourAbilityHandle);
	//RefreshAbilities();
}

uint8 APlayerCharacter::GetTeamID() const
{
	return TeamID;
}

void APlayerCharacter::AddGameplayTag(FGameplayTag& TagToAdd)
{
	GetAbilitySystemComponent()->AddLooseGameplayTag(TagToAdd);
	// SetTagMapCount prevent the tag to be stacked more than one. So when we remove the tag, we know it will be remove completely.
	GetAbilitySystemComponent()->SetTagMapCount(TagToAdd, 1);
}

void APlayerCharacter::RemoveGameplayTag(FGameplayTag& TagToRemove)
{
	GetAbilitySystemComponent()->RemoveLooseGameplayTag(TagToRemove);
}

void APlayerCharacter::AutoDetermineTeamIDbyControllerType()
{
	if (GetController() && GetController()->IsPlayerController())
	{
		TeamID = 0;
	}
}

void APlayerCharacter::Dead()
{
	// Disable the player controller by casting it.
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player has died, disabling input."));
		PC->DisableInput(PC);
	}
	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy AI has died, disabling AI controller."))
		AIC->GetBrainComponent()->StopLogic("Dead");
	}
}

