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
	bScale = true;
	// ...
}


// Called when the game starts
void UExerciceComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	if (AActor* Owner = GetOwner())
	{
		FVector BaseScale = Owner->GetActorScale3D();
	}
}


// Called every frame
void UExerciceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentScale = Owner->GetActorScale3D();
	FVector TargetScaleVector = bScale ? BaseScale * TargetScale : BaseScale;

	if (bScale)
	{
		CurrentScale.X += ScaleSpeed * DeltaTime;
		CurrentScale.Y += ScaleSpeed * DeltaTime;
		CurrentScale.Z += ScaleSpeed * DeltaTime;

		if (CurrentScale.X >= TargetScaleVector.X)
			bScale = false;
	}

	else
	{
		CurrentScale.X -= ScaleSpeed * DeltaTime;
		CurrentScale.Y -= ScaleSpeed * DeltaTime;
		CurrentScale.Z -= ScaleSpeed * DeltaTime;

		if (CurrentScale.X <= TargetScaleVector.X)
			bScale = true;
	}

	Owner->SetActorScale3D(CurrentScale);
}

void UExerciceComponent::StartOscillation()
{
	bIsOscillating = true;
}

void UExerciceComponent::StopOscillation()
{
	bIsOscillating = false;

	if (AActor* Owner = GetOwner())
	{
		Owner->SetActorScale3D(BaseScale);
	}
}
