// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "BaseDoor.h"

// Sets default values
ABaseDoor::ABaseDoor()
{
	bReplicates = true;
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
    if (HasAuthority())
    {
		if(isLock == true)
		{
			if(LockSound)
			{
				FVector Location = GetActorLocation();
        		UGameplayStatics::PlaySoundAtLocation(this, LockSound, Location);
			}
		} else
		{
			isDoorOpen = !isDoorOpen;
			if(isDoorOpen && OpenSound)
			{
				FVector Location = GetActorLocation();
				SoundPlay(OpenSound, Location);
			}
			if(!isDoorOpen && CloseSound)
			{
				FVector Location = GetActorLocation();
				SoundPlay(OpenSound, Location);
			}
		}		
    }
}

void ABaseDoor::SoundPlay_Implementation(USoundBase* Sound, FVector Location)
{
	UGameplayStatics::PlaySoundAtLocation(this, Sound, Location);
}

void ABaseDoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ABaseDoor, isDoorOpen);
	DOREPLIFETIME(ABaseDoor, isLock);
}
