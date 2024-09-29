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
	DoorMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh2"));
	DoorMesh2->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialRotation = DoorMesh->GetRelativeRotation();
	LeftInitialLocation = DoorMesh->GetRelativeLocation();
	if(DoorMesh2){
		RightInitialLocation = DoorMesh2->GetRelativeLocation();
	}
	if(Movement){
		LeftOpenLocation = LeftInitialLocation + FVector(MovementDistance, 0.0f, 0.0f);
		RightOpenLocation = RightInitialLocation + FVector(-MovementDistance, 0.0f, 0.0f);
	} else {
		OpenRotation = InitialRotation + FRotator(0.0f, OpenAngle, 0.0f);
	}
}

// Called every frame
void ABaseDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult HitResult;
	if(isDoorOpen){
		if(Movement){
			if(DoorMesh2){
				FVector CurrentLocation = FMath::Lerp(DoorMesh2->GetRelativeLocation(), RightOpenLocation, DeltaTime * DoorOpenSpeed);
        		DoorMesh2->SetRelativeLocation(CurrentLocation, true, &HitResult);
			}
			FVector CurrentLocation = FMath::Lerp(DoorMesh->GetRelativeLocation(), LeftOpenLocation, DeltaTime * DoorOpenSpeed);
        	DoorMesh->SetRelativeLocation(CurrentLocation, true, &HitResult);
		} else {
			FRotator CurrentRotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), OpenRotation, DeltaTime * DoorOpenSpeed);
			DoorMesh->SetRelativeRotation(CurrentRotation, true, &HitResult);
		}
		
	} else {
		if(Movement){
			if(DoorMesh2){
				FVector CurrentLocation = FMath::Lerp(DoorMesh2->GetRelativeLocation(), RightInitialLocation, DeltaTime * DoorOpenSpeed);
        		DoorMesh2->SetRelativeLocation(CurrentLocation, true, &HitResult);
			}
			FVector CurrentLocation = FMath::Lerp(DoorMesh->GetRelativeLocation(), LeftInitialLocation, DeltaTime * DoorOpenSpeed);
        	DoorMesh->SetRelativeLocation(CurrentLocation, true, &HitResult);
		} else {
			FRotator CurrentRotation = FMath::Lerp(DoorMesh->GetRelativeRotation(), InitialRotation, DeltaTime * DoorOpenSpeed);
			DoorMesh->SetRelativeRotation(CurrentRotation, true, &HitResult);
		}
	}
}

void ABaseDoor::Interact()
{
	isDoorOpen = !isDoorOpen;
}
