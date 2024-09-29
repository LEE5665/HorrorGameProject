// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Widget/InventoryWidget.h"
#include "../../Struct/ItemData.h"
#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	Inventory.SetNum(InventorySlot);
	for (int i = 0; i < Inventory.Num(); i++)
	{
		UE_LOG(LogTemp, Log, TEXT("1"));
	}
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::loadinventory()
{
	UDataTable *MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));
	for (int i = 0; i < Inventory.Num(); i++)
	{

		if (MyDataTable)
		{
			if (Inventory[i].Itemcount != 0)
			{

				UE_LOG(LogTemp, Log, TEXT("데이터 테이블이 로드되었습니다."));
				FName RowName = Inventory[i].ItemID.RowName;
				static const FString ContextString(TEXT("Name"));
				FItemData *FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);
				if (FoundItem)
				{
					UE_LOG(LogTemp, Log, TEXT("아이템 이름: %s, 수량: %d"), *FoundItem->Name.ToString(), Inventory[i].Itemcount);
				}
			}
		}
	}
	if (InventoryWidgetClass)
	{
		InventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), InventoryWidgetClass);
		if(InventoryWidget)
		{
			InventoryWidget->SetInventoryComponent(this);
			InventoryWidget->AddToViewport();
		}
	}
}

void UInventoryComponent::reloadinventory(int32 Number)
{
	if(InventoryWidget){
		InventoryWidget->OnInventoryUpdated(Number);
	}
}
