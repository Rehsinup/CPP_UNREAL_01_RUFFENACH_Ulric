// Fill out your copyright notice in the Description page of Project Settings.


#include "BezierComponent.h"

// Sets default values
ABezierComponent::ABezierComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Timer = 0.0f;
	Actor = 0.0f;

}

// Called when the game starts or when spawned
void ABezierComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABezierComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

