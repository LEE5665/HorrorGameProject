// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Widget/SpectatorWidget.h"
#include "../TP_ThirdPersonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SpectatorPlayer.h"

// void ASpectatorPlayer::PlayerInit()
// {
//     APlayerController *Player = GetLocalViewingPlayerController();
//     if (Player)
//     {
//         SpectatorWidget = CreateWidget<USpectatorWidget>(Player);
//         SpectatorWidget->AddToViewport();
//     }
//     PlayerIndex = 0;
//     if (SeePawn)
//     {
//     }
//     else
//     {
//         TArray<AActor *> FoundActors;
//         UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATP_ThirdPersonCharacter::StaticClass(), FoundActors);

//         for (AActor *Actor : FoundActors)
//         {
//             if (TP_ThirdPersonCharacter* Character = Cast<TP_ThirdPersonCharacter>(Actor))
//             {
//                 PlayerD.Add(Character);
//             }
//         }
//         for(int i = 0;i<PlayerD.Num(); i++){
//             PlayerD[i]
//         }
//     }
// }

// void ASpectatorPlayer::Next()
// {
// }

// void ASpectatorPlayer::prev()
// {
// }
