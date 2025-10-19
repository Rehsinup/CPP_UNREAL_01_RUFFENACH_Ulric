// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceFunction.h"

void UExerciceFunction::PrintMessage(FString Message)
{
    UE_LOG(LogTemp, Error, TEXT("%s"), *Message)
}

FVector UExerciceFunction::TeleportTo(AActor* ActorToTeleport, AActor* TargetActor)
{
    FVector TargetLocation = TargetActor->GetActorLocation();

    ActorToTeleport->SetActorLocation(TargetLocation);;

	return TargetLocation;
}

FVector UExerciceFunction::FindShortestVector(const TArray<FVector>& Vectors)
{
    FVector Shortest = Vectors[0];
    for (const FVector& Vector : Vectors)
        if (Vector.SizeSquared() < Shortest.SizeSquared())
            Shortest = Vector;

    return Shortest;
}

