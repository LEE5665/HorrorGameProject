// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "InteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HORRORPROJECT_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Interact();

	UFUNCTION(Server, Reliable)
	void ServerInteractWithDoor(ABaseDoor *Door);

	UFUNCTION(Server, Reliable)
	void ServerInteractWithItem(ABaseItem* ItemActor, AActor *owner);

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InteractionWidgetClass;
	UUserWidget* InteractionWidget;
	FHitResult nHitActor;
};
