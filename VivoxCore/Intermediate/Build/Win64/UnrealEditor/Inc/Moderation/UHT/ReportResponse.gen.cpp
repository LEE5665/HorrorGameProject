// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Moderation/Public/Models/ReportResponse.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReportResponse() {}

// Begin Cross Module References
MODERATION_API UScriptStruct* Z_Construct_UScriptStruct_FReportResponse();
UPackage* Z_Construct_UPackage__Script_Moderation();
// End Cross Module References

// Begin ScriptStruct FReportResponse
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ReportResponse;
class UScriptStruct* FReportResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ReportResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ReportResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FReportResponse, (UObject*)Z_Construct_UPackage__Script_Moderation(), TEXT("ReportResponse"));
	}
	return Z_Registration_Info_UScriptStruct_ReportResponse.OuterSingleton;
}
template<> MODERATION_API UScriptStruct* StaticStruct<FReportResponse>()
{
	return FReportResponse::StaticStruct();
}
struct Z_Construct_UScriptStruct_FReportResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * @brief Struct representing a moderation report response.\n */" },
#endif
		{ "ModuleRelativePath", "Public/Models/ReportResponse.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Struct representing a moderation report response." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWasSuccessful_MetaData[] = {
		{ "Category", "Unity Gaming Services | Moderation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*!< Whether the response was a success. */" },
#endif
		{ "ModuleRelativePath", "Public/Models/ReportResponse.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "!< Whether the response was a success." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FReportResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FReportResponse_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((FReportResponse*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FReportResponse_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FReportResponse), &Z_Construct_UScriptStruct_FReportResponse_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWasSuccessful_MetaData), NewProp_bWasSuccessful_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FReportResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FReportResponse_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReportResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FReportResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Moderation,
	nullptr,
	&NewStructOps,
	"ReportResponse",
	Z_Construct_UScriptStruct_FReportResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReportResponse_Statics::PropPointers),
	sizeof(FReportResponse),
	alignof(FReportResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FReportResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FReportResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FReportResponse()
{
	if (!Z_Registration_Info_UScriptStruct_ReportResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ReportResponse.InnerSingleton, Z_Construct_UScriptStruct_FReportResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ReportResponse.InnerSingleton;
}
// End ScriptStruct FReportResponse

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_ReportResponse_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FReportResponse::StaticStruct, Z_Construct_UScriptStruct_FReportResponse_Statics::NewStructOps, TEXT("ReportResponse"), &Z_Registration_Info_UScriptStruct_ReportResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FReportResponse), 3421149352U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_ReportResponse_h_899728124(TEXT("/Script/Moderation"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_ReportResponse_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_HorrorProject_Plugins_VivoxCore_Source_Moderation_Public_Models_ReportResponse_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
