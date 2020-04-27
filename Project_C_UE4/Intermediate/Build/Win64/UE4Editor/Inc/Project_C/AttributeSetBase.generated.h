// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_C_AttributeSetBase_generated_h
#error "AttributeSetBase.generated.h already included, missing '#pragma once' in AttributeSetBase.h"
#endif
#define PROJECT_C_AttributeSetBase_generated_h

#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_18_DELEGATE \
struct _Script_Project_C_eventOnAttributeChangeDelegate_Parms \
{ \
	float Attr; \
	float MaxAttr; \
}; \
static inline void FOnAttributeChangeDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnAttributeChangeDelegate, float Attr, float MaxAttr) \
{ \
	_Script_Project_C_eventOnAttributeChangeDelegate_Parms Parms; \
	Parms.Attr=Attr; \
	Parms.MaxAttr=MaxAttr; \
	OnAttributeChangeDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_SPARSE_DATA
#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_RPC_WRAPPERS
#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttributeSetBase(); \
	friend struct Z_Construct_UClass_UAttributeSetBase_Statics; \
public: \
	DECLARE_CLASS(UAttributeSetBase, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Project_C"), NO_API) \
	DECLARE_SERIALIZER(UAttributeSetBase)


#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUAttributeSetBase(); \
	friend struct Z_Construct_UClass_UAttributeSetBase_Statics; \
public: \
	DECLARE_CLASS(UAttributeSetBase, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Project_C"), NO_API) \
	DECLARE_SERIALIZER(UAttributeSetBase)


#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAttributeSetBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAttributeSetBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttributeSetBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttributeSetBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAttributeSetBase(UAttributeSetBase&&); \
	NO_API UAttributeSetBase(const UAttributeSetBase&); \
public:


#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAttributeSetBase(UAttributeSetBase&&); \
	NO_API UAttributeSetBase(const UAttributeSetBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttributeSetBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttributeSetBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAttributeSetBase)


#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_PRIVATE_PROPERTY_OFFSET
#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_20_PROLOG
#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_PRIVATE_PROPERTY_OFFSET \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_SPARSE_DATA \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_RPC_WRAPPERS \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_INCLASS \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_PRIVATE_PROPERTY_OFFSET \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_SPARSE_DATA \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_INCLASS_NO_PURE_DECLS \
	Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_C_API UClass* StaticClass<class UAttributeSetBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_C_UE4_Source_Project_C_Public_AttributeSetBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
