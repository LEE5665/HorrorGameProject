#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundBase.h"
#include "Engine/DataTable.h"
#include "SFX.h"
#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class EMotion : uint8
{
    Default   UMETA(DisplayName = "Default"),
    FlashLight   UMETA(DisplayName = "FlashLight")
};


USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    FName Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    UTexture2D* Image;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    TSubclassOf<class ABaseItem> Class;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    FSFX SFX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    EMotion Motion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    int32 SlotQuantity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    FVector AttachLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    FRotator AttachRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties")
    FVector AttachScale;
    

    FItemData()
        : Name(FText::FromString("Default Name"))
        , Description(FName("Default Description"))
        , Image(nullptr)
        , Class(nullptr)
        , Motion(EMotion::Default)
        , SlotQuantity(1)
        , AttachLocation(FVector::ZeroVector)
        , AttachRotation(FRotator::ZeroRotator)
        , AttachScale(FVector(1.0f, 1.0f, 1.0f))
    {}
};