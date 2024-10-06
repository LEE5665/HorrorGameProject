// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StatusWidget.generated.h"

/**
 * 
 */
UCLASS()
class HORRORPROJECT_API UStatusWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
    void OnStatusUpdated();
	void SetActor(AActor* Actor);
	UPROPERTY(BlueprintReadWrite)
	AActor* Player;
};
