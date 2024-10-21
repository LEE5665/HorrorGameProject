// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModeration_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Moderation;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Moderation()
	{
		if (!Z_Registration_Info_UPackage__Script_Moderation.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Moderation",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xACC7BF8C,
				0x81161C44,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Moderation.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Moderation.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Moderation(Z_Construct_UPackage__Script_Moderation, TEXT("/Script/Moderation"), Z_Registration_Info_UPackage__Script_Moderation, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xACC7BF8C, 0x81161C44));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
