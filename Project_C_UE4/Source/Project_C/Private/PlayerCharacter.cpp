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
	AttributeBaseComp->OnStrengthChange.AddDynamic(this, &APlayerCharacter::OnStrengthChanged);

	AutoDetermineTeamIDbyControllerType();
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

void APlayerCharacter::OnStrengthChanged(float Strength, float MaxStrength)
{
	BP_OnStrengthChanged(Strength, MaxStrength);
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
	RefreshAbilities();
}

void APlayerCharacter::EquipSecondaryAbility(TSubclassOf<UGameplayAbility> Ability)
{
	this->SecondarySlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipHeadSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->HeadSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipChestSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->ChestSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipArmsSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->ArmsSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipLegsSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->LegsSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipSkillOneSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillOneSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipSkillTwoSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillTwoSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipSkillThreeSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillThreeSlot = Ability;
	RefreshAbilities();
}

void APlayerCharacter::EquipSkillFourSlot(TSubclassOf<UGameplayAbility> Ability)
{
	this->SkillFourSlot = Ability;
	RefreshAbilities();
}

uint8 APlayerCharacter::GetTeamID() const
{
	return TeamID;
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

