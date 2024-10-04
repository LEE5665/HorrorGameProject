// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseItem.h"
#include "../Component/Player/InventoryComponent.h"
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "../Struct/ItemData.h"

// Sets default values
ABaseItem::ABaseItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseItem::Use_Implementation()
{
	UE_LOG(LogTemp,Log,TEXT("베이스아이템 Use 실행"));
}

void ABaseItem::AddItem(AActor *inventoryOwner)
{
	if (inventoryOwner)
	{
		UInventoryComponent *InventoryComp = inventoryOwner->FindComponentByClass<UInventoryComponent>();
		if (InventoryComp)
		{
			bool ItemAdded = false;
			UDataTable *MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));
			if (MyDataTable)
			{
				FName RowName = itemdata.ItemID.RowName;
				static const FString ContextString(TEXT("Name"));
				FItemData *FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);
				if (FoundItem)
				{
					SlotCount = FoundItem->SlotQuantity;
				}
			}
			for (int i = 0; i < InventoryComp->Inventory.Num(); i++)
			{
				if (InventoryComp->Inventory[i].ItemID == itemdata.ItemID)
				{
					if (InventoryComp->Inventory[i].Itemcount < SlotCount)
					{
						int32 AvailableSpace = SlotCount - InventoryComp->Inventory[i].Itemcount;
						int32 AddAmount = FMath::Min(itemdata.Itemcount, AvailableSpace);

						InventoryComp->Inventory[i].Itemcount += AddAmount;
						itemdata.Itemcount -= AddAmount;

						UE_LOG(LogTemp, Log, TEXT("같은 아이템 %s이(가) %d개 추가되었습니다. 현재 개수: %d"), *itemdata.ItemID.RowName.ToString(), AddAmount, InventoryComp->Inventory[i].Itemcount);

						if (itemdata.Itemcount <= 0)
						{
							ItemAdded = true;
							ATP_ThirdPersonCharacter *Ch = Cast<ATP_ThirdPersonCharacter>(inventoryOwner);
							InventoryComp->reloadinventory(Ch->SelectInventory);
							Destroy();
							return;
						}
					}
				}
			}
			for (int i = 0; i < InventoryComp->Inventory.Num(); i++)
			{
				if (InventoryComp->Inventory[i].Itemcount == 0)
				{
					InventoryComp->Inventory[i] = itemdata;
					ItemAdded = true;
					UE_LOG(LogTemp, Log, TEXT("남은 아이템 %s이(가) 인벤토리의 빈 슬롯에 추가되었습니다. 추가된 개수: %d"), *itemdata.ItemID.RowName.ToString(), itemdata.Itemcount);
					ItemAdded = true;
					ATP_ThirdPersonCharacter *Ch = Cast<ATP_ThirdPersonCharacter>(inventoryOwner);
					InventoryComp->reloadinventory(Ch->SelectInventory);
					Destroy();
					return;
				}
			}
			if (!ItemAdded)
			{
				UE_LOG(LogTemp, Warning, TEXT("인벤토리에 빈 슬롯이 없거나 아이템을 추가할 수 없습니다."));
			}
		}
	}
}