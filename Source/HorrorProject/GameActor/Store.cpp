// Fill out your copyright notice in the Description page of Project Settings.

#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "../Component/Player/InventoryComponent.h"
#include "../Struct/ItemData.h"
#include "../BaseActor/BaseItem.h"
#include "../Struct/Item.h"
#include "Kismet/GameplayStatics.h"
#include "Store.h"

// Sets default values
AStore::AStore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStore::Interact_Implementation(AActor *PlayerActor)
{
	ATP_ThirdPersonCharacter *Player = Cast<ATP_ThirdPersonCharacter>(PlayerActor);
	UE_LOG(LogTemp, Log, TEXT("%s"), *Player->GetName());
	if(Player->InventoryComponent->AttachItem){
		FItemData *Item = GetRowFromDataTable(Player->InventoryComponent->AttachItem->itemdata.ItemID.RowName);
		UE_LOG(LogTemp, Log, TEXT("%s"), *Item->Name.ToString());
		SellItem(Player, Item->SellPrice);
		Player->InventoryComponent->DropItem(Player->SelectInventory, false);
	}
}

FItemData* AStore::GetRowFromDataTable(FName RowName)
{
	UDataTable *MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));
	static const FString ContextString(TEXT("Name"));
	FItemData *FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);
	if(FoundItem) {
		return FoundItem;
	} else {
		return nullptr;
	}
}
