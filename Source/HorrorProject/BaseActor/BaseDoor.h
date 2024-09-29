// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDoor.generated.h"

UCLASS()
class HORRORPROJECT_API ABaseDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact();

private:
	bool isDoorOpen = false;
	FRotator InitialRotation;
	FRotator OpenRotation;
	FVector LeftInitialLocation;
	FVector RightInitialLocation;
	FVector LeftOpenLocation;
	FVector RightOpenLocation;

	UPROPERTY(EditAnyWhere, Category="Door")
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnyWhere, Category="Door")
	float DoorOpenSpeed = 2.0f;

	UPROPERTY(VisibleAnywhere, Category="Door")
    class UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, Category="Door")
    class UStaticMeshComponent* DoorMesh2;

	UPROPERTY(EditAnyWhere, Category="Door")
	bool Movement = false;

	UPROPERTY(EditAnyWhere, Category="Door")
	float MovementDistance = 10.0f;
};
