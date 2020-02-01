// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GGJ2020/GGJ2020HUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGGJ2020HUD() {}
// Cross Module References
	GGJ2020_API UClass* Z_Construct_UClass_AGGJ2020HUD_NoRegister();
	GGJ2020_API UClass* Z_Construct_UClass_AGGJ2020HUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_GGJ2020();
// End Cross Module References
	void AGGJ2020HUD::StaticRegisterNativesAGGJ2020HUD()
	{
	}
	UClass* Z_Construct_UClass_AGGJ2020HUD_NoRegister()
	{
		return AGGJ2020HUD::StaticClass();
	}
	struct Z_Construct_UClass_AGGJ2020HUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGGJ2020HUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_GGJ2020,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGGJ2020HUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "GGJ2020HUD.h" },
		{ "ModuleRelativePath", "GGJ2020HUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGGJ2020HUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGGJ2020HUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGGJ2020HUD_Statics::ClassParams = {
		&AGGJ2020HUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGGJ2020HUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGGJ2020HUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGGJ2020HUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGGJ2020HUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGGJ2020HUD, 4144696660);
	template<> GGJ2020_API UClass* StaticClass<AGGJ2020HUD>()
	{
		return AGGJ2020HUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGGJ2020HUD(Z_Construct_UClass_AGGJ2020HUD, &AGGJ2020HUD::StaticClass, TEXT("/Script/GGJ2020"), TEXT("AGGJ2020HUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGGJ2020HUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
