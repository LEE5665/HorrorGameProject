// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "../Component/Player/InventoryComponent.h"
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
    
	// 데이터 테이블 로드
	// UDataTable* MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));

	// if (MyDataTable)
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("데이터 테이블이 로드되었습니다."));

	// 	// 이름으로 행을 검색
	// 	FName RowName = itemdata.ItemID;
	// 	static const FString ContextString(TEXT("Name"));
	// 	FItemData* FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);

	// 	if (FoundItem)
	// 	{
	// 		// 데이터 가져오기 성공
	// 		UE_LOG(LogTemp, Log, TEXT("아이템 이름: %s, 수량: %d"), *FoundItem->Name.ToString(), FoundItem->SlotQuantity);
	// 	}
	// }
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseItem::AddItem(AActor* inventoryOwner)
{
	if(inventoryOwner){
		UInventoryComponent* InventoryComp = inventoryOwner->FindComponentByClass<UInventoryComponent>();
		if(InventoryComp){
			bool ItemAdded = false;
			for(int i=0;i<InventoryComp->Inventory.Num(); i++){
				if(InventoryComp->Inventory[i].Itemcount == 0){
                    InventoryComp->Inventory[i] = itemdata;
                    ItemAdded = true;
                    UE_LOG(LogTemp, Log, TEXT("아이템 %s이(가) 인벤토리의 빈 슬롯에 추가되었습니다."), *itemdata.ItemID.RowName.ToString());
					InventoryComp->loadinventory();
					Destroy();
                    break;
				}
			}
			if(!ItemAdded){
				UE_LOG(LogTemp, Warning, TEXT("인벤토리에 빈 슬롯이 없습니다."));
			}
		}
	}
}
