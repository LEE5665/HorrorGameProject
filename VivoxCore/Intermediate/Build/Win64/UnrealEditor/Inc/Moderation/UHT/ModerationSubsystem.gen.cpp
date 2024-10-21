// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Moderation/Public/ModerationSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModerationSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
MODERATION_API UClass* Z_Construct_UClass_UModerationSubsystem();
MODERATION_API UClass* Z_Construct_UClass_UModerationSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Moderation();
// End Cross Module References

// Begin Class UModerationSubsystem
void UModerationSubsystem::StaticRegisterNativesUModerationSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UModerationSubsystem);
UClass* Z_Construct_UClass_UModerationSubsystem_NoRegister()
{
	return UModerationSubsystem::StaticClass();
}
struct Z_Construct_UClass_UModerationSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * @brief Subsystem for handling connections to the Unity Moderation system.\n */" },
#endif
		{ "IncludePath", "ModerationSubsystem.h" },
		{ "ModuleRelativePath", "Public/ModerationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Subsystem for handling connections to the Unity Moderation system." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModerationSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UModerationSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Moderation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModerationSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModerationSubsystem_Statics::ClassParams = {
	&UModerationSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModerationSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UModerationSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UModerationSubsystem()
{
	if (!Z_Registration_Info_UClass_UModerationSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModerationSubsystem.OuterSingleton, Z_Construct_UClass_UModerationSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModerationSubsystem.OuterSingleton;
}
template<> MODERATION_API UClass* StaticClass<UModerationSubsystem>()
{
	return UModerationSubsystem::StaticClass();
}
// End Class UModerationSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_ModerationSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModerationSubsystem, UModerationSubsystem::StaticClass, TEXT("UModerationSubsystem"), &Z_Registration_Info_UClass_UModerationSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModerationSubsystem), 3087467859U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_ModerationSubsystem_h_2407618056(TEXT("/Script/Moderation"),
	Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_ModerationSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_ModerationSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
