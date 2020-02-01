// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GGJ2020/GGJ2020GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGGJ2020GameMode() {}
// Cross Module References
	GGJ2020_API UClass* Z_Construct_UClass_AGGJ2020GameMode_NoRegister();
	GGJ2020_API UClass* Z_Construct_UClass_AGGJ2020GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GGJ2020();
// End Cross Module References
	void AGGJ2020GameMode::StaticRegisterNativesAGGJ2020GameMode()
	{
	}
	UClass* Z_Construct_UClass_AGGJ2020GameMode_NoRegister()
	{
		return AGGJ2020GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGGJ2020GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGGJ2020GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GGJ2020,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGGJ2020GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GGJ2020GameMode.h" },
		{ "ModuleRelativePath", "GGJ2020GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGGJ2020GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGGJ2020GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGGJ2020GameMode_Statics::ClassParams = {
		&AGGJ2020GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGGJ2020GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGGJ2020GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGGJ2020GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGGJ2020GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGGJ2020GameMode, 4247573977);
	template<> GGJ2020_API UClass* StaticClass<AGGJ2020GameMode>()
	{
		return AGGJ2020GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGGJ2020GameMode(Z_Construct_UClass_AGGJ2020GameMode, &AGGJ2020GameMode::StaticClass, TEXT("/Script/GGJ2020"), TEXT("AGGJ2020GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGGJ2020GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
