// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/Interact.h"
#include "Store.generated.h"

struct FItemData;

UCLASS()
class HORRORPROJECT_API AStore : public AActor, public IInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStore();

	UFUNCTION(BlueprintImplementableEvent)
	void SellItem(ATP_ThirdPersonCharacter *Player, int32 SellMoney);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact_Implementation(AActor *PlayerActor) override;
private:
	FItemData* GetRowFromDataTable(FName RowName);
};
