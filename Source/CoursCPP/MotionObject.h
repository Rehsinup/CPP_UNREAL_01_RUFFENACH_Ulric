// Fill out your copyright notice in the Description page of Project Settings.
/*
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTools.h"
#include "MotionObject.generated.h"

UCLASS()
class COURSCPP_API AMotionObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMotionObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartBezierInterpolation();

	UFONCTION(BlueprintCallable)
		void RotateTo(FVector TargetDirection, float Duration);
	UFONCTION(BlueprintCallable)
		void ScaleTo(FVector Scale, float Duration);

	


private:
	UStaticMeshComponent* CreateBezierPoint(const int& Index);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Visual")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Bezier")
	USceneComponent* BezierPointList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Bezier")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Bezier")
	int PointCount;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Bezier")
	TArray<UStaticMeshComponent*> BezierPoint;



	USceneComponent* Root;
	UStaticMesh* SphereMesh;
	float Timer;
	bool Interpolate;
	TArray<FVector> PointLocations;
};
*/