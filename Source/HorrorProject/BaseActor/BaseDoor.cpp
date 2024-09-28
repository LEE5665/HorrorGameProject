// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "BaseDoor.h"

// Sets default values
ABaseDoor::ABaseDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!RootComponent)
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    }
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialRotation = DoorMesh->GetRelativeRotation();
	OpenRotation = InitialRotation + FRotator(0.0f, OpenAngle, 0.0f);
}

// Called every frame
void ABaseDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(isDoorOpen){
		FRotator CurrentRotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), OpenRotation, DeltaTime * DoorOpenSpeed);
		DoorMesh->SetRelativeRotation(CurrentRotation);
	} else {
		FRotator CurrentRotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), InitialRotation, DeltaTime * DoorOpenSpeed);
		DoorMesh->SetRelativeRotation(CurrentRotation);
	}
}

void ABaseDoor::Interact()
{
	isDoorOpen = !isDoorOpen;
}
