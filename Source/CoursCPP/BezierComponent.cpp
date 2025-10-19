// Fill out your copyright notice in the Description page of Project Settings.


#include "BezierComponent.h"

// Sets default values for this component's properties
UBezierComponent::UBezierComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Duration = 0.0f;
	Timer = 0.0f;
	Points = TArray<FVector>();
	Owner = nullptr;
	// ...
}


// Called when the game starts
void UBezierComponent::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	// ...
	
}


// Called every frame
void UBezierComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Timer += DeltaTime;

	float Alpha = FMath::Clamp(Timer / Duration, 0, 1);

	FVector Position = UMyTools::BezierInterp(Points, Alpha);

	Owner->SetActorLocation(Position);
	// ...
}

