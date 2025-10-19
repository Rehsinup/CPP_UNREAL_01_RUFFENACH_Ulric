// Fill out your copyright notice in the Description page of Project Settings.


#include "MotionObject.h"

// Sets default values
AMotionObject::AMotionObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Création de la racine de l'objet
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	BezierPointList = CreateDefaultSubobject<USceneComponent>(TEXT("BezierPointList"));
	BezierPointList->SetupAttachment(Root);

	//On crée le static mesh et on l'attache à la racine 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	//On cherche le mesh du cube puis on le met dans le StaticMeshComponent
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube"));
	if (CubeMesh.Succeeded())
		Mesh->SetStaticMesh(CubeMesh.Object);
	else
		CubeMesh = nullptr;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshFinder(TEXT("/Game/LevelPrototyping/Meshes/SM_QuarterCylinder.SM_QuarterCylinder"));
	if (SphereMeshFinder.Succeeded())
		Mesh->SetStaticMesh(SphereMeshFinder.Object);
	else
		SphereMesh = nullptr;

	PointCount = 0;
	Duration = 0.0f;
	Timer = 0.0f;
	PointLocations = TArray<FVector>();
	Interpolate = false;
}

// Called when the game starts or when spawned
void AMotionObject::BeginPlay()
{
	Super::BeginPlay();

}

void AMotionObject::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	int pointCountDelta = PointCount - BezierPoint.Num();

	if (pointCountDelta == 0)
		return;

	if (pointCountDelta > 0)
	{
		//Créer des points
		for (int i = 0; i < pointCountDelta; i++)
		{
			BezierPoint.Add(CreateBezierPoint(BezierPoint.Num()));
		}
	}

	else
	{
		for (int i =BezierPoint.Num() -1; i >= PointCount; i--)
		{
			UStaticMeshComponent* Point = BezierPoint.Pop();
			Point->DestroyComponent();
		}
		//Détruire
	}

	//if (BezierPoint != nullptr)
	//{
	//	BezierPoint->DestroyComponent();
	//	BezierPoint = nullptr;
	//}

	////On crée le composant
	//BezierPoint = NewObject<UStaticMeshComponent>(this, FName("Point"));

	////On notifie à l'objet que le composant appartient à l'objet
	//BezierPoint->RegisterComponent();

	////AttachToComponent
	//BezierPoint->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	//BezierPoint->SetStaticMesh(SphereMesh);
	//BezierPoint->bHiddenInGame = true;
	//BezierPoint->SetCollisionProfileName("NoCollision");
	//BezierPoint->SetWorldScale3D(FVector(0.1f));
}

// Called every frame
void AMotionObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Interpolate)
		return;

	Timer += DeltaTime;

	float Alpha = FMath::Clamp(Timer / Duration, 0, 1);

	FVector Position = UMyTools::BezierInterp(PointLocations, Alpha);

	Mesh->SetWorldLocation(Position);

}

void AMotionObject::StartBezierInterpolation()
{
	Interpolate = true;
	Timer = 0.0f;

	PointLocations = TArray<FVector>();

	for (int i = 0; i < PointCount; i++)
	{
		PointLocations.Add(BezierPoint[i]->GetComponentLocation());
	}
}

UStaticMeshComponent* AMotionObject::CreateBezierPoint(const int& Index)
{

	//On crée le composant
	FName PointName = FName("Point_" + FString::FromInt(Index+1));
	UStaticMeshComponent* Point = NewObject<UStaticMeshComponent>(this, FName("Point"));

	//On notifie à l'objet que le composant appartient à l'objet
	Point->RegisterComponent();

	//AttachToComponent
	Point->AttachToComponent(BezierPointList, FAttachmentTransformRules::KeepRelativeTransform);

	Point->SetStaticMesh(SphereMesh);
	Point->bHiddenInGame = true;
	Point->SetCollisionProfileName("NoCollision");
	Point->SetWorldScale3D(FVector(0.1f));
	
	return Point;
}

