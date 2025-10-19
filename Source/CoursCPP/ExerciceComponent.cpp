// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceComponent.h"

// Sets default values for this component's properties
UExerciceComponent::UExerciceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	BaseScale = FVector::ZeroVector;
	TargetScale = 1.0f;
	ScaleSpeed = 1.0f;

	bIsOscillating = false;
	Owner = GetOwner();
	// ...
}


// Called when the game starts
void UExerciceComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	if (Owner != nullptr)
	{
		BaseScale = Owner->GetActorScale3D();
	}
}


// Called every frame
void UExerciceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIsOscillating)
		return;


	OscillationTime += bIncreasing ? DeltaTime * ScaleSpeed : -DeltaTime * ScaleSpeed;

	if (OscillationTime >= 1.0f)
	{
		OscillationTime = 1.0f;
		bIncreasing = false;
	}
	else if (OscillationTime <= 0.0f)
	{
		OscillationTime = 0.0f;
		bIncreasing = true;
	}

	FVector NewScale = FMath::Lerp(BaseScale, BaseScale * TargetScale, OscillationTime);

	Owner->SetActorScale3D(NewScale);
}

void UExerciceComponent::StartOscillation()
{
	bIsOscillating = true;
}

void UExerciceComponent::StopOscillation()
{
	bIsOscillating = false;

		Owner->SetActorScale3D(BaseScale);

}
