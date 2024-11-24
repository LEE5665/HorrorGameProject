// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpectatorWidget.generated.h"

/**
 * 
 */
UCLASS()
class HORRORPROJECT_API USpectatorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
UFUNCTION(BlueprintImplementableEvent, Category = "Spectator")
    void OnNameChange(FName Name);
};
