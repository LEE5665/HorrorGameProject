// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "StatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HORRORPROJECT_API UStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatusComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)
	int32 MaxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_CurrentHealth)
	int32 CurrentHealth = 100;
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_IsRun)
	bool IsRun = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxStamina = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentStamina = 100;
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> StatusWidgetClass;
	UPROPERTY(BlueprintReadWrite)
	class UStatusWidget* StatusWidget;
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void RunStatus(bool Set);
	UPROPERTY()
	class UCharacterMovementComponent* MovementComponent;
	UFUNCTION()
	void OnRep_IsRun();
	UFUNCTION(BlueprintCallable)
	void OnRep_CurrentHealth();

private:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};
