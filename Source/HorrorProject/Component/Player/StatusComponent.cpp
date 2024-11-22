// Fill out your copyright notice in the Description page of Project Settings.
#include "Net/UnrealNetwork.h"
#include "../../Widget/StatusWidget.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "StatusComponent.h"

// Sets default values for this component's properties
UStatusComponent::UStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatusComponent::BeginPlay()
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
				if (StatusWidgetClass)
				{
					StatusWidget = CreateWidget<UStatusWidget>(PlayerController, StatusWidgetClass);
					if (StatusWidget)
					{
						StatusWidget->AddToViewport();
					}
				}
			}
		}
	}
	
}


// Called every frame
void UStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatusComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UStatusComponent, MaxHealth);
	DOREPLIFETIME(UStatusComponent, CurrentHealth);
	DOREPLIFETIME(UStatusComponent, IsRun);
}

void UStatusComponent::RunStatus_Implementation(bool Set)
{
	ACharacter *CharacterOwner = Cast<ACharacter>(GetOwner());
	if (CharacterOwner)
	{
		MovementComponent = CharacterOwner->GetCharacterMovement();
	}

	if (Set)
	{
		if (CurrentStamina >= 5)
		{
			if (MovementComponent)
			{
				MovementComponent->MaxWalkSpeed = 500;
				IsRun = Set;
			}
		}
	}
	else
	{
		if (MovementComponent)
		{
			MovementComponent->MaxWalkSpeed = 250;
			IsRun = Set;
		}
	}
}

void UStatusComponent::OnRep_IsRun()
{
	ACharacter *CharacterOwner = Cast<ACharacter>(GetOwner());
	if (CharacterOwner)
	{
		MovementComponent = CharacterOwner->GetCharacterMovement();
	}
	if (IsRun)
	{
		if (CurrentStamina >= 5)
		{
			if (MovementComponent)
			{
				MovementComponent->MaxWalkSpeed = 500;
			}
		}
	}
	else
	{
		if (MovementComponent)
		{
			MovementComponent->MaxWalkSpeed = 250;
		}
	}
}
