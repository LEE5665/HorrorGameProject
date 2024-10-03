// Fill out your copyright notice in the Description page of Project Settings.

#include "../../BaseActor/BaseDoor.h"
#include "../../BaseActor/BaseItem.h"
#include "InteractComponent.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

// Called when the game starts
void UInteractComponent::BeginPlay()
{
    Super::BeginPlay();

    AActor *Owner = GetOwner();
    if (Owner)
    {
        APawn *Pawn = Cast<APawn>(Owner);
        if (Pawn && Pawn->IsLocallyControlled())
        {
            APlayerController *PlayerController = Cast<APlayerController>(Pawn->GetController());
            if (PlayerController)
            {
                if (InteractionWidgetClass)
                {
                    InteractionWidget = CreateWidget<UUserWidget>(PlayerController, InteractionWidgetClass);
                    if (InteractionWidget)
                    {
                        InteractionWidget->AddToViewport();
                        InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
                    }
                }
            }
        }
    }
}

// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FHitResult HitResult;

    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(GetOwner());

    APawn *Pawn = Cast<APawn>(GetOwner());
    if (Pawn && InteractionWidget)
    {
        APlayerController *PlayerController = Cast<APlayerController>(Pawn->GetController());
        if (PlayerController) // PlayerController가 널이 아닌지 체크
        {
            FVector CameraLocation;
            FRotator CameraRotation;
            PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);
            FVector Start = CameraLocation;
            FVector End = Start + (CameraRotation.Vector() * 200.0f);

            bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);
            // DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 2.0f);

            if (bHit && HitResult.GetActor() && HitResult.GetComponent())
            {
                if (HitResult.GetComponent()->ComponentHasTag(FName("Hit")))
                {
                    nHitActor = HitResult;
                    InteractionWidget->SetVisibility(ESlateVisibility::Visible);
                }
                else
                {
                    nHitActor = FHitResult();
                    InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
                }
            }
            else
            {
                nHitActor = FHitResult();
                InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
            }
        }
    }
}

void UInteractComponent::Interact()
{
    if (nHitActor.GetActor())
    {
        AActor *HitActor = nHitActor.GetActor();
        if (nHitActor.GetComponent()->ComponentHasTag(FName("Door")))
        {
            ABaseDoor *DoorActor = Cast<ABaseDoor>(HitActor);
            if (DoorActor)
            {
                ServerInteractWithDoor(DoorActor);
                UE_LOG(LogTemp, Log, TEXT("Interacted with Door!"));
            }
        }
        else if (nHitActor.GetComponent()->ComponentHasTag(FName("Item")))
        {
            ABaseItem *ItemActor = Cast<ABaseItem>(HitActor);
            if (ItemActor)
            {
                ServerInteractWithItem(ItemActor, GetOwner());
                // ItemActor->AddItem();
                UE_LOG(LogTemp, Log, TEXT("Picked up Item!"));
            }
        }
    }
}

void UInteractComponent::ServerInteractWithDoor_Implementation(ABaseDoor *Door)
{
    Door->Interact();
}

void UInteractComponent::ServerInteractWithItem_Implementation(ABaseItem *ItemActor, AActor *owner)
{
    ItemActor->AddItem(owner);
}
