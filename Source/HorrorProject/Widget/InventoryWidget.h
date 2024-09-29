// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Component/Player/InventoryComponent.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class HORRORPROJECT_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void SetInventoryComponent(class UInventoryComponent* InInventoryComponent);

    UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
    void OnInventoryUpdated(int32 Number);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (ExposeOnSpawn = true))
    UInventoryComponent* InventoryComponent;

};
