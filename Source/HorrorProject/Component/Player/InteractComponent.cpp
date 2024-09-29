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
	if (InteractionWidgetClass)
	{
		InteractionWidget = CreateWidget<UUserWidget>(GetWorld(), InteractionWidgetClass);

		if (InteractionWidget)
		{
			InteractionWidget->AddToViewport();
			InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	AActor *Owner = GetOwner();
	if (Owner && Owner->InputComponent)
	{
		Owner->InputComponent->BindAction("IA_Interact", IE_Pressed, this, &UInteractComponent::Interact);
	}
}

// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult HitResult;

	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(GetOwner());

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FVector CameraLocation;
    FRotator CameraRotation;
	PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);
	FVector Start = CameraLocation;
    FVector End = Start + (CameraRotation.Vector() * 200.0f);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 2.0f);

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

void UInteractComponent::Interact()
{
    if (nHitActor.GetActor())
    {
        AActor* HitActor = nHitActor.GetActor();
        if (nHitActor.GetComponent()->ComponentHasTag(FName("Door")))
        {
            ABaseDoor* DoorActor = Cast<ABaseDoor>(HitActor);
            if (DoorActor)
            {
                DoorActor->Interact();
                UE_LOG(LogTemp, Log, TEXT("Interacted with Door!"));
            }
        }
        else if (nHitActor.GetComponent()->ComponentHasTag(FName("Item")))
        {
            ABaseItem* ItemActor = Cast<ABaseItem>(HitActor);
            if (ItemActor)
            {
                ItemActor->AddItem(GetOwner());
                UE_LOG(LogTemp, Log, TEXT("Picked up Item!"));
            }
        }
    }
}