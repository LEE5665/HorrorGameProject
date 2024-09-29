// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundBase.h"
#include "UObject/NoExportTypes.h"
#include "SFX.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSFX
{
    GENERATED_BODY()

public:
	FSFX()
        : PickUp(nullptr),
        Drop(nullptr),
        Use(nullptr)
    {}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundBase* PickUp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundBase* Drop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundBase* Use;
};