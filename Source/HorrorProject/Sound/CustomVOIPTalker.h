// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/VoiceConfig.h"
#include "Components/AudioComponent.h"
#include "CustomVOIPTalker.generated.h"

/**
 * 
 */
UCLASS()
class HORRORPROJECT_API UCustomVOIPTalker : public UVOIPTalker
{
	GENERATED_BODY()

public:
	virtual void OnTalkingBegin(UAudioComponent* AudioComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VOIP")
    float PlayerVolume = 1.0f;

	UPROPERTY()
    UAudioComponent* CurrentAudioComponent;

	UFUNCTION(BlueprintCallable, Category = "VOIP")
    void UpdateVolume();
};
