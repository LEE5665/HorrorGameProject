// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VivoxCore/Public/Channel3DProperties.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChannel3DProperties() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_VivoxCore();
VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_EAudioFadeModel();
// End Cross Module References

// Begin Enum EAudioFadeModel
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAudioFadeModel;
static UEnum* EAudioFadeModel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAudioFadeModel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAudioFadeModel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_EAudioFadeModel, (UObject*)Z_Construct_UPackage__Script_VivoxCore(), TEXT("EAudioFadeModel"));
	}
	return Z_Registration_Info_UEnum_EAudioFadeModel.OuterSingleton;
}
template<> VIVOXCORE_API UEnum* StaticEnum<EAudioFadeModel>()
{
	return EAudioFadeModel_StaticEnum();
}
struct Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n  * \\brief The distance model for a Positional ChannelType, which determines the algorithm to use when computing attenuation.\n  */" },
#endif
		{ "ExponentialByDistance.Comment", "/**\n     * \\brief Makes voice within the conversational distance louder, but fade quickly beyond it.\n     */" },
		{ "ExponentialByDistance.Name", "EAudioFadeModel::ExponentialByDistance" },
		{ "ExponentialByDistance.ToolTip", "\\brief Makes voice within the conversational distance louder, but fade quickly beyond it." },
		{ "InverseByDistance.Comment", "/**\n     * \\brief Fades voice quickly at first, buts slows down as you get further from conversational distance.\n     */" },
		{ "InverseByDistance.Name", "EAudioFadeModel::InverseByDistance" },
		{ "InverseByDistance.ToolTip", "\\brief Fades voice quickly at first, buts slows down as you get further from conversational distance." },
		{ "LinearByDistance.Comment", "/**\n     * \\brief Fades voice slowly at first, but speeds up as you get further from conversational distance.\n     */" },
		{ "LinearByDistance.Name", "EAudioFadeModel::LinearByDistance" },
		{ "LinearByDistance.ToolTip", "\\brief Fades voice slowly at first, but speeds up as you get further from conversational distance." },
		{ "ModuleRelativePath", "Public/Channel3DProperties.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief The distance model for a Positional ChannelType, which determines the algorithm to use when computing attenuation." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAudioFadeModel::InverseByDistance", (int64)EAudioFadeModel::InverseByDistance },
		{ "EAudioFadeModel::LinearByDistance", (int64)EAudioFadeModel::LinearByDistance },
		{ "EAudioFadeModel::ExponentialByDistance", (int64)EAudioFadeModel::ExponentialByDistance },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
	nullptr,
	"EAudioFadeModel",
	"EAudioFadeModel",
	Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_VivoxCore_EAudioFadeModel()
{
	if (!Z_Registration_Info_UEnum_EAudioFadeModel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAudioFadeModel.InnerSingleton, Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAudioFadeModel.InnerSingleton;
}
// End Enum EAudioFadeModel

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAudioFadeModel_StaticEnum, TEXT("EAudioFadeModel"), &Z_Registration_Info_UEnum_EAudioFadeModel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3747796302U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_2956326530(TEXT("/Script/VivoxCore"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_VivoxCore_Public_Channel3DProperties_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
