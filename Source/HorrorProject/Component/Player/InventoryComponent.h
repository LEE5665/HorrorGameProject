// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../Struct/Item.h"
#include "Blueprint/UserWidget.h"
#include "InventoryComponent.generated.h"


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
    FVector AttachLocation;
    FRotator AttachRotation;
    FVector AttachScale;

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
	void ServerAttachItem(int32 Number);

	void ChAttachItem(int32 Number);

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 InventorySlot = 6;

	void loadinventory();

	void reloadinventory(int32 Number);

	UFUNCTION(Server, Reliable)
	void DropItem(int32 Number);

	UFUNCTION()
	void OnRep_Inventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_HandItem, Category = "Inventory")
	class ABaseItem *AttachItem;

	UFUNCTION()
	void OnRep_HandItem();

	

	// UFUNCTION(BlueprintCallable, Category = "Inventory")
	// bool AddItem(const FItem& NewItem);
};
