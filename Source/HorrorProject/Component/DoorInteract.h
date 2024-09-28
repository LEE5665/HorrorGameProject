// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractInterface.h"
#include "DoorInteract.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HORRORPROJECT_API UDoorInteract : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteract();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Interact_Implementation() override;
	virtual FString GetName_Implementation() const override;

private:
	bool isDoorOpen = false;
	FRotator InitialRotation;
	FRotator OpenRotation;

	UPROPERTY(EditAnyWhere, Category="Door")
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnyWhere, Category="Door")
	float DoorOpenSpeed = 2.0f;

	UPROPERTY(VisibleAnywhere, Category="Door")
    class UStaticMeshComponent* DoorMesh;
};
