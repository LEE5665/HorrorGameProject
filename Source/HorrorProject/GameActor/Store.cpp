// Fill out your copyright notice in the Description page of Project Settings.

#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Store.h"

// Sets default values
AStore::AStore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStore::Interact_Implementation(AActor *PlayerActor)
{
	ATP_ThirdPersonCharacter *Player = Cast<ATP_ThirdPersonCharacter>(PlayerActor);
	UE_LOG(LogTemp, Log, TEXT("%s"), *Player->GetName());
	
}
