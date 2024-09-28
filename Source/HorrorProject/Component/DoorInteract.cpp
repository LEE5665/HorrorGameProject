// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteract.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UDoorInteract::UDoorInteract()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	isDoorOpen = false;
}


// Called when the game starts
void UDoorInteract::BeginPlay()
{
	Super::BeginPlay();
	DoorMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	InitialRotation = DoorMesh->GetRelativeRotation();
	OpenRotation = InitialRotation + FRotator(0.0f, OpenAngle, 0.0f);
}


// Called every frame
void UDoorInteract::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(isDoorOpen){
		FRotator CurrentRotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), OpenRotation, DeltaTime * DoorOpenSpeed);
		DoorMesh->SetRelativeRotation(CurrentRotation);
	} else {
		FRotator CurrentRotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), InitialRotation, DeltaTime * DoorOpenSpeed);
		DoorMesh->SetRelativeRotation(CurrentRotation);
	}
}

void UDoorInteract::Interact_Implementation()
{
	isDoorOpen = !isDoorOpen;
}

FString UDoorInteract::GetName_Implementation() const
{
	if(isDoorOpen){
		FString message = "XXX";
		return message;
	}
	FString message = "OOO";
    return message;
}
