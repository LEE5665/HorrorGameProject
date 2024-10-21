// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Moderation/Public/Models/Report.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReport() {}

// Begin Cross Module References
MODERATION_API UScriptStruct* Z_Construct_UScriptStruct_FReport();
UPackage* Z_Construct_UPackage__Script_Moderation();
// End Cross Module References

// Begin ScriptStruct FReport
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Report;
class UScriptStruct* FReport::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Report.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Report.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FReport, (UObject*)Z_Construct_UPackage__Script_Moderation(), TEXT("Report"));
	}
	return Z_Registration_Info_UScriptStruct_Report.OuterSingleton;
}
template<> MODERATION_API UScriptStruct* StaticStruct<FReport>()
{
	return FReport::StaticStruct();
}
struct Z_Construct_UScriptStruct_FReport_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * @brief Struct representing options for authentication sign-in calls.\n */" },
#endif
		{ "ModuleRelativePath", "Public/Models/Report.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Struct representing options for authentication sign-in calls." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReportReason_MetaData[] = {
		{ "Category", "Unity Gaming Services | Moderation | Models" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*!< The reason that the report is being made. */" },
#endif
		{ "ModuleRelativePath", "Public/Models/Report.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "!< The reason that the report is being made." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReportedUnityPlayerID_MetaData[] = {
		{ "Category", "Unity Gaming Services | Moderation | Models" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*!< The Unity Authentication Player Id of the Reported Player. */" },
#endif
		{ "ModuleRelativePath", "Public/Models/Report.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "!< The Unity Authentication Player Id of the Reported Player." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReportedVivoxURI_MetaData[] = {
		{ "Category", "Unity Gaming Services | Moderation | Models" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*!<The Vivox Sip URI of the Reported Player. */" },
#endif
		{ "ModuleRelativePath", "Public/Models/Report.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "!<The Vivox Sip URI of the Reported Player." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReportingVivoxURI_MetaData[] = {
		{ "Category", "Unity Gaming Services | Moderation | Models" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*!<The Vivox Sip URI of the Reporting Player. */" },
#endif
		{ "ModuleRelativePath", "Public/Models/Report.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "!<The Vivox Sip URI of the Reporting Player." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReportReason;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReportedUnityPlayerID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReportedVivoxURI;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReportingVivoxURI;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FReport>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportReason = { "ReportReason", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReport, ReportReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReportReason_MetaData), NewProp_ReportReason_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportedUnityPlayerID = { "ReportedUnityPlayerID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReport, ReportedUnityPlayerID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReportedUnityPlayerID_MetaData), NewProp_ReportedUnityPlayerID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportedVivoxURI = { "ReportedVivoxURI", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReport, ReportedVivoxURI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReportedVivoxURI_MetaData), NewProp_ReportedVivoxURI_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportingVivoxURI = { "ReportingVivoxURI", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FReport, ReportingVivoxURI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReportingVivoxURI_MetaData), NewProp_ReportingVivoxURI_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FReport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportedUnityPlayerID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportedVivoxURI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReport_Statics::NewProp_ReportingVivoxURI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReport_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FReport_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Moderation,
	nullptr,
	&NewStructOps,
	"Report",
	Z_Construct_UScriptStruct_FReport_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReport_Statics::PropPointers),
	sizeof(FReport),
	alignof(FReport),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReport_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FReport_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FReport()
{
	if (!Z_Registration_Info_UScriptStruct_Report.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Report.InnerSingleton, Z_Construct_UScriptStruct_FReport_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Report.InnerSingleton;
}
// End ScriptStruct FReport

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_Report_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FReport::StaticStruct, Z_Construct_UScriptStruct_FReport_Statics::NewStructOps, TEXT("Report"), &Z_Registration_Info_UScriptStruct_Report, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FReport), 786769139U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_Report_h_243408636(TEXT("/Script/Moderation"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_Report_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_Report_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
