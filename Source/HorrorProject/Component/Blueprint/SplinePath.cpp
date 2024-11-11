// SplinePath.cpp
#include "SplinePath.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"

// 생성자
ASplinePath::ASplinePath()
{
    PrimaryActorTick.bCanEverTick = true;

    // 스플라인 컴포넌트 생성 및 설정
    SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
    RootComponent = SplineComponent;

    // 기본 메쉬 할당
    SplineMesh = nullptr;
}

// OnConstruction: 에디터에서 액터가 배치되거나 수정될 때 호출됨
void ASplinePath::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    float DefaultSegmentLength = 200.0f; // 기본 세그먼트 길이
    if (SplineMesh)
    {
        GenerateSplineMesh(DefaultSegmentLength);
    }
}

// 메쉬를 설정하는 함수
void ASplinePath::SetSplineMesh(UStaticMesh* Mesh)
{
    SplineMesh = Mesh;

    if (SplineMesh)
    {
        UE_LOG(LogTemp, Warning, TEXT("SplineMesh has been set!"));
        GenerateSplineMesh(200.0f);
    }
}

// 스플라인을 따라 메쉬 생성
void ASplinePath::GenerateSplineMesh(float SegmentLength)
{
    if (!SplineMesh || !SplineComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("SplineMesh or SplineComponent is null!"));
        return;
    }

    // 기존 메쉬 삭제
    for (USplineMeshComponent* SplineMeshComp : SplineMeshes)
    {
        if (SplineMeshComp)
        {
            SplineMeshComp->DestroyComponent();
        }
    }
    SplineMeshes.Empty();

    // 스플라인 길이 및 세그먼트 수 계산
    float SplineLength = SplineComponent->GetSplineLength();
    int32 NumSegments = FMath::CeilToInt(SplineLength / SegmentLength);

    for (int32 i = 0; i < NumSegments; ++i)
    {
        float StartDistance = i * SegmentLength;
        float EndDistance = FMath::Min((i + 1) * SegmentLength, SplineLength);

        FVector StartLocation = SplineComponent->GetLocationAtDistanceAlongSpline(StartDistance, ESplineCoordinateSpace::World);
        FVector StartTangent = SplineComponent->GetTangentAtDistanceAlongSpline(StartDistance, ESplineCoordinateSpace::World);
        FVector EndLocation = SplineComponent->GetLocationAtDistanceAlongSpline(EndDistance, ESplineCoordinateSpace::World);
        FVector EndTangent = SplineComponent->GetTangentAtDistanceAlongSpline(EndDistance, ESplineCoordinateSpace::World);

        // 스플라인 메쉬 생성 및 등록
        USplineMeshComponent* SplineMeshComp = NewObject<USplineMeshComponent>(this);
        SplineMeshComp->SetStaticMesh(SplineMesh);
        SplineMeshComp->SetStartAndEnd(StartLocation, StartTangent, EndLocation, EndTangent);
        SplineMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        SplineMeshComp->RegisterComponentWithWorld(GetWorld());

        SplineMeshes.Add(SplineMeshComp);
    }

    UE_LOG(LogTemp, Warning, TEXT("SplineMesh generated with %d segments"), NumSegments);
}
