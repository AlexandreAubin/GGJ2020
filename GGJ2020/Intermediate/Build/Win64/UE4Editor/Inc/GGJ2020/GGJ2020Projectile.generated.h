// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef GGJ2020_GGJ2020Projectile_generated_h
#error "GGJ2020Projectile.generated.h already included, missing '#pragma once' in GGJ2020Projectile.h"
#endif
#define GGJ2020_GGJ2020Projectile_generated_h

#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_SPARSE_DATA
#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGGJ2020Projectile(); \
	friend struct Z_Construct_UClass_AGGJ2020Projectile_Statics; \
public: \
	DECLARE_CLASS(AGGJ2020Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GGJ2020"), NO_API) \
	DECLARE_SERIALIZER(AGGJ2020Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGGJ2020Projectile(); \
	friend struct Z_Construct_UClass_AGGJ2020Projectile_Statics; \
public: \
	DECLARE_CLASS(AGGJ2020Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GGJ2020"), NO_API) \
	DECLARE_SERIALIZER(AGGJ2020Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGGJ2020Projectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGGJ2020Projectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGGJ2020Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGGJ2020Projectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGGJ2020Projectile(AGGJ2020Projectile&&); \
	NO_API AGGJ2020Projectile(const AGGJ2020Projectile&); \
public:


#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGGJ2020Projectile(AGGJ2020Projectile&&); \
	NO_API AGGJ2020Projectile(const AGGJ2020Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGGJ2020Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGGJ2020Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGGJ2020Projectile)


#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AGGJ2020Projectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AGGJ2020Projectile, ProjectileMovement); }


#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_9_PROLOG
#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_SPARSE_DATA \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_RPC_WRAPPERS \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_INCLASS \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_SPARSE_DATA \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_INCLASS_NO_PURE_DECLS \
	GGJ2020_Source_GGJ2020_GGJ2020Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GGJ2020_API UClass* StaticClass<class AGGJ2020Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GGJ2020_Source_GGJ2020_GGJ2020Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
