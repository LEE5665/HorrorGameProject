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
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = Start + (GetOwner()->GetActorForwardVector() * 200.0f);

	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);
	// DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 2.0f);

	if (bHit && HitResult.GetActor())
	{
		if (HitResult.GetActor()->ActorHasTag(FName("Hit")))
		{
			nHitActor = HitResult.GetActor();
			InteractionWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			nHitActor = nullptr;
			InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else
	{
		nHitActor = nullptr;
		InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UInteractComponent::Interact()
{
	if (nHitActor)
	{
		if (nHitActor->ActorHasTag(FName("Door")))
		{
			ABaseDoor *DoorActor = Cast<ABaseDoor>(nHitActor);
			if (DoorActor)
			{
				DoorActor->Interact();
				UE_LOG(LogTemp, Log, TEXT("Interacted with Door!"));
			}
		} else if(nHitActor->ActorHasTag(FName("Item")))
		{
			ABaseItem *ItemActor = Cast<ABaseItem>(nHitActor);
			if(ItemActor)
			{
				ItemActor->AddItem(GetOwner());
			}
		}
	}
}