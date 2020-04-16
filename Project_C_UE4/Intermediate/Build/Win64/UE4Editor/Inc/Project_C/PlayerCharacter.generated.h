// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGameplayAbility;
class APlayerCharacter;
#ifdef PROJECT_C_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define PROJECT_C_PlayerCharacter_generated_h

#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_SPARSE_DATA
#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEquipSkillFourSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillFourSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSkillThreeSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillThreeSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSkillTwoSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillTwoSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSkillOneSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillOneSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipLegsSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipLegsSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipArmsSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipArmsSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipChestSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipChestSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipHeadSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipHeadSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSecondaryAbility) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSecondaryAbility(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipPrimaryAbility) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipPrimaryAbility(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRefreshAbilities) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RefreshAbilities(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsOtherHostile) \
	{ \
		P_GET_OBJECT(APlayerCharacter,Z_Param_Other); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsOtherHostile(Z_Param_Other); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnStrengthChanged) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxStrength); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnStrengthChanged(Z_Param_Strength,Z_Param_MaxStrength); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnManaChanged) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Mana); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxMana); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnManaChanged(Z_Param_Mana,Z_Param_MaxMana); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHealthChanged) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Health); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxHealth); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHealthChanged(Z_Param_Health,Z_Param_MaxHealth); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAcquireAbility) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_AbilityToAcquire); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AcquireAbility(Z_Param_AbilityToAcquire); \
		P_NATIVE_END; \
	}


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEquipSkillFourSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillFourSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSkillThreeSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillThreeSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSkillTwoSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillTwoSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSkillOneSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSkillOneSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipLegsSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipLegsSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipArmsSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipArmsSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipChestSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipChestSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipHeadSlot) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipHeadSlot(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipSecondaryAbility) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipSecondaryAbility(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEquipPrimaryAbility) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_Ability); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EquipPrimaryAbility(Z_Param_Ability); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRefreshAbilities) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RefreshAbilities(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsOtherHostile) \
	{ \
		P_GET_OBJECT(APlayerCharacter,Z_Param_Other); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsOtherHostile(Z_Param_Other); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnStrengthChanged) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxStrength); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnStrengthChanged(Z_Param_Strength,Z_Param_MaxStrength); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnManaChanged) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Mana); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxMana); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnManaChanged(Z_Param_Mana,Z_Param_MaxMana); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHealthChanged) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Health); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxHealth); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHealthChanged(Z_Param_Health,Z_Param_MaxHealth); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAcquireAbility) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_AbilityToAcquire); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AcquireAbility(Z_Param_AbilityToAcquire); \
		P_NATIVE_END; \
	}


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_EVENT_PARMS \
	struct PlayerCharacter_eventBP_OnhealthChanged_Parms \
	{ \
		float Health; \
		float Maxhealth; \
	}; \
	struct PlayerCharacter_eventBP_OnManaChanged_Parms \
	{ \
		float Mana; \
		float MaxMana; \
	}; \
	struct PlayerCharacter_eventBP_OnStrengthChanged_Parms \
	{ \
		float Strength; \
		float MaxStrength; \
	};


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_CALLBACK_WRAPPERS
#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_C"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<APlayerCharacter*>(this); }


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_C"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<APlayerCharacter*>(this); }


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public:


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerCharacter)


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PrimarySlot() { return STRUCT_OFFSET(APlayerCharacter, PrimarySlot); } \
	FORCEINLINE static uint32 __PPO__SecondarySlot() { return STRUCT_OFFSET(APlayerCharacter, SecondarySlot); } \
	FORCEINLINE static uint32 __PPO__HeadSlot() { return STRUCT_OFFSET(APlayerCharacter, HeadSlot); } \
	FORCEINLINE static uint32 __PPO__ChestSlot() { return STRUCT_OFFSET(APlayerCharacter, ChestSlot); } \
	FORCEINLINE static uint32 __PPO__ArmsSlot() { return STRUCT_OFFSET(APlayerCharacter, ArmsSlot); } \
	FORCEINLINE static uint32 __PPO__LegsSlot() { return STRUCT_OFFSET(APlayerCharacter, LegsSlot); } \
	FORCEINLINE static uint32 __PPO__SkillOneSlot() { return STRUCT_OFFSET(APlayerCharacter, SkillOneSlot); } \
	FORCEINLINE static uint32 __PPO__SkillTwoSlot() { return STRUCT_OFFSET(APlayerCharacter, SkillTwoSlot); } \
	FORCEINLINE static uint32 __PPO__SkillThreeSlot() { return STRUCT_OFFSET(APlayerCharacter, SkillThreeSlot); } \
	FORCEINLINE static uint32 __PPO__SkillFourSlot() { return STRUCT_OFFSET(APlayerCharacter, SkillFourSlot); }


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_14_PROLOG \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_EVENT_PARMS


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_SPARSE_DATA \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_RPC_WRAPPERS \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_CALLBACK_WRAPPERS \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_INCLASS \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_SPARSE_DATA \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_CALLBACK_WRAPPERS \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_INCLASS_NO_PURE_DECLS \
	Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_C_API UClass* StaticClass<class APlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
