// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Struct/Item.h"
#include "BaseItem.generated.h"

UCLASS()
class HORRORPROJECT_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddItem(AActor* inventoryOwner);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	FItem itemdata;
	int32 SlotCount = 1;
};
