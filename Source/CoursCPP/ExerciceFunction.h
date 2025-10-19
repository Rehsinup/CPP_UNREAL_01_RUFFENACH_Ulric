// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExerciceFunction.generated.h"

/**
 * 
 */
UCLASS()
class COURSCPP_API UExerciceFunction : public UObject
{
	GENERATED_BODY()
	

	
public:

	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintMessage(FString Message);

	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	static FVector TeleportTo(AActor* ActorToTeleport, AActor* TargetActor);

	UFUNCTION(BlueprintPure, Category = "Vector")
	static FVector FindShortestVector(const TArray<FVector>& Vector);
};
