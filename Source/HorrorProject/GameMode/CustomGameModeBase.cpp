// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameModeBase.h"

void ACustomGameModeBase::GetSeamlessTravelActorList(bool bToTransition, TArray<AActor*>& ActorList)
{
    ActorList = K2_OnGetSeamlessTravelActorList(bToTransition, ActorList);
    Super::GetSeamlessTravelActorList(bToTransition, ActorList);
}

