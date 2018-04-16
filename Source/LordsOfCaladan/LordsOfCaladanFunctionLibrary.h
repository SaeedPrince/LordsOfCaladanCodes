// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerStart.h"
#include "LordsOfCaladanFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LORDSOFCALADAN_API ULordsOfCaladanFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Character|Type")
		static FString GetPlayerStartType(class APlayerStart* playerStart);

	UFUNCTION(BlueprintPure, Category = "Math|Clamp")
		static float ClampFloat(float MustClamp, float Min, float Max);

	UFUNCTION(BlueprintPure, Category = "Actor|Spawn")
		static FTransform MakeSpawnTransform(class AActor* InputActor);

	UFUNCTION(BlueprintPure, Category = "Pawn|Movement")
		static FRotator MakeRotatorByZ(FRotator InputRotator);

	UFUNCTION(BlueprintPure, Category = "Pawn|Movement")
		static FVector GetForwardVector(FRotator InRot);

	UFUNCTION(BlueprintPure, Category = "Pawn|Movement")
		static FVector GetRightVector(FRotator InRot);

	UFUNCTION(BlueprintPure, Category = "Pawn|Movement")
		static FVector GetMovementVector(FRotator InputRotator, FString Direction);

	UFUNCTION(BlueprintPure, Category = "Time|Addition")
		static FDateTime AddOneScaledSecond(FDateTime InputTime);
};
