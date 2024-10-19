// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomVOIPTalker.h"

void UCustomVOIPTalker::OnTalkingBegin(UAudioComponent *AudioComponent)
{
    Super::OnTalkingBegin(AudioComponent);

    if (AudioComponent)
    {
        CurrentAudioComponent = AudioComponent;
        CurrentAudioComponent->SetVolumeMultiplier(PlayerVolume);
    }
}

void UCustomVOIPTalker::UpdateVolume()
{
    if (CurrentAudioComponent)
    {
        CurrentAudioComponent->AdjustVolume(0.001f, PlayerVolume);
    }
}
