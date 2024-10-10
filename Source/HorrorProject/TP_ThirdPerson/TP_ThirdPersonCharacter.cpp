// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonCharacter.h"
#include "../Component/Player/InteractComponent.h"
#include "../Component/Player/InventoryComponent.h"
#include "Engine/LocalPlayer.h"
#include "../BaseActor/BaseItem.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../Component/Player/StatusComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ATP_ThirdPersonCharacter

ATP_ThirdPersonCharacter::ATP_ThirdPersonCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
	InteractComponent = CreateDefaultSubobject<UInteractComponent>(TEXT("InteractComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
}

void ATP_ThirdPersonCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATP_ThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::Look);
		EnhancedInputComponent->BindAction(Interact, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::interact);
		EnhancedInputComponent->BindAction(InventorySlot, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::SelectInventorySlot);
		EnhancedInputComponent->BindAction(DropAction, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::Drop);
		EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::LeftClick);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &ATP_ThirdPersonCharacter::RunHold);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ATP_ThirdPersonCharacter::RunCompleted);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ATP_ThirdPersonCharacter::interact()
{
	InteractComponent->Interact();
}

void ATP_ThirdPersonCharacter::Drop(){
	InventoryComponent->DropItem(SelectInventory, true);
}

void ATP_ThirdPersonCharacter::LeftClick()
{
	InventoryComponent->ServerUse();
}

void ATP_ThirdPersonCharacter::RunHold()
{
	StatusComponent->RunStatus(true);
}
void ATP_ThirdPersonCharacter::RunCompleted()
{
	StatusComponent->RunStatus(false);
}

void ATP_ThirdPersonCharacter::SelectInventorySlot(const FInputActionValue &Value)
{
    float SlotNumber = Value.Get<float>();
	if(FMath::RoundToInt(SlotNumber)-1 == SelectInventory)
		return;
	InventoryComponent->PastInventorySlot=SelectInventory;
	SelectInventory = FMath::RoundToInt(SlotNumber)-1;
	UE_LOG(LogTemp, Log, TEXT("Inventory Slot %d selected"), SelectInventory);
	ServerSelectInventorySlot(SelectInventory);
	InventoryComponent->reloadinventory();
}
void ATP_ThirdPersonCharacter::ServerSelectInventorySlot_Implementation(int32 Number)
{
	SelectInventory = Number;
	if(InventoryComponent->AttachItem)
	{
		InventoryComponent->AttachItem->Destroy();
		InventoryComponent->AttachItem=nullptr;
	}
}

void ATP_ThirdPersonCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATP_ThirdPersonCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ATP_ThirdPersonCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ATP_ThirdPersonCharacter, CurrentMotion);
	DOREPLIFETIME(ATP_ThirdPersonCharacter, SelectInventory);
}