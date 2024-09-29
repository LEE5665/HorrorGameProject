// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FItem
{
    GENERATED_BODY()

public:
	FItem()
        : Itemcount(0)
    {}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
    FDataTableRowHandle ItemID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
    int32 Itemcount;
};