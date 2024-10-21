// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "CustomGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HORRORPROJECT_API ACustomGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

    void GetSeamlessTravelActorList(bool bToTransition, TArray<AActor*>& ActorList);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Game, meta = (DisplayName = "GetSeamlessTravelActorList", ScriptName = "GetSeamlessTravelActorList"))
    TArray<AActor*> K2_OnGetSeamlessTravelActorList(bool bToTransitionOut, UPARAM(ref)TArray<AActor*>& ActorListOut);
};
