// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../Struct/Item.h"
#include "Blueprint/UserWidget.h"
#include "InventoryComponent.generated.h"

class ABaseItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HORRORPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// UPROPERTY(Replicated)
    // FVector AttachLocation;
	// UPROPERTY(Replicated)
    // FRotator AttachRotation;
	// UPROPERTY(Replicated)
    // FVector AttachScale;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY(BlueprintReadWrite);
	class UInventoryWidget* InventoryWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_Inventory, Category = "Inventory")
	TArray<FItem> Inventory;

	UFUNCTION(Server, Reliable)
	void ServerAttachItem();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 InventorySlot = 6;

	UFUNCTION(BlueprintCallable)
	void reloadinventory();

	UFUNCTION(Server, Reliable)
	void DropItem(int32 Number, bool DropItemSpawn);

	UFUNCTION(Server, Reliable)
	void ServerMotion(int32 selectedinventory);

	UFUNCTION()
	void OnRep_Inventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_HandItem, Category = "Inventory")
	ABaseItem *AttachItem;

	UFUNCTION()
	void OnRep_HandItem();

	UFUNCTION(Server, Reliable)
	void ServerUse();

	int32 PastInventorySlot = 0;

	// UFUNCTION(BlueprintCallable, Category = "Inventory")
	// bool AddItem(const FItem& NewItem);
};
