// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Widget/InventoryWidget.h"
#include "../../Struct/ItemData.h"
#include "../../BaseActor/BaseItem.h"
#include "../../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "../../Interface/Battery.h"
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
	AActor *Owner = GetOwner();
	if (Owner)
	{
		APawn *Pawn = Cast<APawn>(Owner);
		if (Pawn && Pawn->IsLocallyControlled())
		{
			APlayerController *PlayerController = Cast<APlayerController>(Pawn->GetController());
			if (PlayerController)
			{
				if (InventoryWidgetClass)
				{
					InventoryWidget = CreateWidget<UInventoryWidget>(PlayerController, InventoryWidgetClass);
					if (InventoryWidget)
					{
						InventoryWidget->SetInventoryComponent(this);
						InventoryWidget->AddToViewport();
					}
				}
			}
		}
	}
}

void UInventoryComponent::ServerUse_Implementation()
{
	if (GetOwner()->HasAuthority())
	{
		if (AttachItem)
		{
			AttachItem->Use();
		}
	}
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::reloadinventory(bool AttachLoad)
{
	if (InventoryWidget)
	{
		ATP_ThirdPersonCharacter *Ch = Cast<ATP_ThirdPersonCharacter>(GetOwner());
		InventoryWidget->OnInventoryUpdated(Ch->SelectInventory);
		if (AttachLoad == true)
		{
			ServerAttachItem(Ch->SelectInventory);
		}
	}
}

void UInventoryComponent::ServerAttachItem_Implementation(int32 Number)
{
	ChAttachItem(Number);
}

void UInventoryComponent::ChAttachItem(int32 Number)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (AttachItem)
		{
			AttachItem->Destroy();
		}

		UDataTable *MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));
		if (MyDataTable && Inventory[Number].Itemcount != 0)
		{
			FName RowName = Inventory[Number].ItemID.RowName;
			static const FString ContextString(TEXT("Name"));
			FItemData *FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);
			if (FoundItem)
			{
				UWorld *World = GetWorld();
				if (World && FoundItem->Class)
				{
					AttachItem = World->SpawnActor<ABaseItem>(FoundItem->Class);
					AttachItem->SetOwner(GetOwner());
					if (AttachItem)
					{
						UStaticMeshComponent *StaticMeshComp = Cast<UStaticMeshComponent>(AttachItem->GetComponentByClass(UStaticMeshComponent::StaticClass()));
						if (StaticMeshComp)
						{
							StaticMeshComp->SetSimulatePhysics(false);
						}
						AActor *Owner = GetOwner();
						if (Owner && GetOwnerRole() == ROLE_Authority)
						{
							TArray<USkeletalMeshComponent *> SkeletalMeshes;
							Owner->GetComponents<USkeletalMeshComponent>(SkeletalMeshes);
							for (USkeletalMeshComponent *Mesh : SkeletalMeshes)
							{
								if (Mesh)
								{
									if (Mesh->ComponentHasTag("Body"))
									{
										AttachItem->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Ep"));
										AttachItem->SetActorRelativeLocation(FoundItem->AttachLocation);
										AttachItem->SetActorRelativeScale3D(FoundItem->AttachScale);
										AttachItem->SetActorRelativeRotation(FoundItem->AttachRotation);

										if (AttachItem->GetClass()->ImplementsInterface(UBattery::StaticClass()))
										{
											IBattery::Execute_SetBatteryLevel(AttachItem, Inventory[Number].Currentbattery);
											UE_LOG(LogTemp, Warning, TEXT("%d"), IBattery::Execute_GetBatteryLevel(AttachItem));
											
										}
									}
								}
							}
						}
						UE_LOG(LogTemp, Log, TEXT("서버에서 아이템 %s 생성 완료"), *FoundItem->Name.ToString());
					}
				}
			}
		}
	}
}

void UInventoryComponent::OnRep_Inventory()
{
	ATP_ThirdPersonCharacter *Ch = Cast<ATP_ThirdPersonCharacter>(GetOwner());
	if (Inventory[Ch->SelectInventory].Itemcount == 0)
	{
		reloadinventory(true);
		return;
	}
	if (InventoryWidget)
	{
		InventoryWidget->OnInventoryUpdated(Ch->SelectInventory);
		if (AttachItem)
		{
			reloadinventory(false);
		}
		else
		{
			reloadinventory(true);
		}
	}
}

void UInventoryComponent::OnRep_HandItem()
{
	if (AttachItem)
	{
		AttachItem->SetOwner(GetOwner());
		ATP_ThirdPersonCharacter *Ch = Cast<ATP_ThirdPersonCharacter>(GetOwner());
		UDataTable *MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));
		if (MyDataTable && Inventory[Ch->SelectInventory].Itemcount != 0)
		{
			FName RowName = Inventory[Ch->SelectInventory].ItemID.RowName;
			static const FString ContextString(TEXT("Name"));
			FItemData *FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);
			if (FoundItem)
			{
				AActor *Owner = GetOwner();
				if (Owner)
				{
					TArray<USkeletalMeshComponent *> SkeletalMeshes;
					Owner->GetComponents<USkeletalMeshComponent>(SkeletalMeshes);
					for (USkeletalMeshComponent *Mesh : SkeletalMeshes)
					{
						if (Mesh)
						{
							if (Mesh->ComponentHasTag("Body"))
							{
								AttachItem->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Ep"));
								AttachItem->SetActorRelativeLocation(FoundItem->AttachLocation);
								AttachItem->SetActorRelativeRotation(FoundItem->AttachRotation);
								AttachItem->SetActorRelativeScale3D(FoundItem->AttachScale);
								UE_LOG(LogTemp, Log, TEXT("클라이언트에서 아이템 부착 완료"));
							}
						}
					}
				}
			}
		}
	}
}

void UInventoryComponent::DropItem_Implementation(int32 Number, bool DropItemSpawn)
{

	UDataTable *MyDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/06_Inventory/ItemData/DT_ItemData.DT_ItemData"));
	if (Inventory[Number].Itemcount == 0)
		return;
	if (MyDataTable)
	{
		FName RowName = Inventory[Number].ItemID.RowName;
		static const FString ContextString(TEXT("Name"));
		FItemData *FoundItem = MyDataTable->FindRow<FItemData>(RowName, ContextString);
		if (FoundItem)
		{
			UWorld *World = GetWorld();
			if (World && FoundItem->Class)
			{
				if (DropItemSpawn)
				{
					FVector SpawnLocation = GetOwner()->GetActorLocation();
					FRotator SpawnRotation = GetOwner()->GetActorRotation();

					ABaseItem *SpawnedItem = World->SpawnActor<ABaseItem>(FoundItem->Class, SpawnLocation, SpawnRotation);
					if (SpawnedItem)
					{
						SpawnedItem->itemdata.ItemID = Inventory[Number].ItemID;
						SpawnedItem->itemdata.Itemcount = 1;
						if (SpawnedItem->GetClass()->ImplementsInterface(UBattery::StaticClass()))
						{
							bool Isuse = IBattery::Execute_GetSwitch(AttachItem);
							IBattery::Execute_SetBatteryLevel(SpawnedItem, IBattery::Execute_GetBatteryLevel(AttachItem));
							IBattery::Execute_SetSwitch(SpawnedItem, Isuse);
						}
					}
				}
				Inventory[Number].Itemcount--;
				if (Inventory[Number].Itemcount == 0)
				{
					Inventory[Number].ItemID.RowName = FName("None");
				}
				reloadinventory(true);
			}
		}
	}
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UInventoryComponent, Inventory);
	DOREPLIFETIME(UInventoryComponent, AttachItem);
}