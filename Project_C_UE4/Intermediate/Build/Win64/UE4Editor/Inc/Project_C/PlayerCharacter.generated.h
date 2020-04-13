// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerCharacter;
class UGameplayAbility;
#ifdef PROJECT_C_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define PROJECT_C_PlayerCharacter_generated_h

#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_SPARSE_DATA
#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_RPC_WRAPPERS \
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
	DECLARE_FUNCTION(execAcquireAbillity) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_AbilityToAcquire); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AcquireAbillity(Z_Param_AbilityToAcquire); \
		P_NATIVE_END; \
	}


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
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
	DECLARE_FUNCTION(execAcquireAbillity) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_AbilityToAcquire); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AcquireAbillity(Z_Param_AbilityToAcquire); \
		P_NATIVE_END; \
	}


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_EVENT_PARMS \
	struct PlayerCharacter_eventBP_OnhealthChanged_Parms \
	{ \
		float Health; \
		float Maxhealth; \
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


#define Project_C_UE4_Source_Project_C_Public_PlayerCharacter_h_17_PRIVATE_PROPERTY_OFFSET
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
