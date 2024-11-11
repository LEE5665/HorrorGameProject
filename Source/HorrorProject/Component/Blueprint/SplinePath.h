// SplinePath.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "SplinePath.generated.h"

UCLASS()
class HORRORPROJECT_API ASplinePath : public AActor
{
    GENERATED_BODY()

public:
    ASplinePath();

protected:
    virtual void OnConstruction(const FTransform& Transform) override;

public:

    // 스플라인 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline")
    USplineComponent* SplineComponent;

    // 스플라인을 따라 메쉬를 생성하는 함수
    UFUNCTION(BlueprintCallable, Category = "Spline")
    void GenerateSplineMesh(float SegmentLength);

    // 스플라인에 사용할 메쉬를 설정하는 함수
    UFUNCTION(BlueprintCallable, Category = "Spline")
    void SetSplineMesh(UStaticMesh* Mesh);

private:
    TArray<USplineMeshComponent*> SplineMeshes;

    // 스플라인에 사용할 기본 메쉬
    UPROPERTY(EditAnywhere, Category = "Spline")
    UStaticMesh* SplineMesh;
};
