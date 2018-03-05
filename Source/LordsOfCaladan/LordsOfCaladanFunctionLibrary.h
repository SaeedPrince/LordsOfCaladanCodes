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

	
	
};
