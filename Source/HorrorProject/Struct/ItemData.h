#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundBase.h"
#include "Engine/DataTable.h"
#include "SFX.h"
#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class ESFX : uint8
{
    PickupSound   UMETA(DisplayName = "Pickup"),
    DropSound     UMETA(DisplayName = "Drop"),
    UseSound      UMETA(DisplayName = "Use")
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
    int32 SlotQuantity;

    FItemData()
        : Name(FText::FromString("Default Name"))
        , Description(FName("Default Description"))
        , Image(nullptr)
        , Class(nullptr)
        , SlotQuantity(1)
    {}
};