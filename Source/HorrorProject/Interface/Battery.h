// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Battery.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UBattery : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HORRORPROJECT_API IBattery
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Battery")
	int32 GetBatteryLevel();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Battery")
	int32 GetMaxBatteryLevel();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Battery")
	void SetBatteryLevel(int32 NewBatteryLevel);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Battery")
	bool GetSwitch();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Battery")
	void SetSwitch(bool Setting);
};
