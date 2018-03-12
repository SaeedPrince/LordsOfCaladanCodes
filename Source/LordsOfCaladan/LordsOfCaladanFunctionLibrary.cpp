// Fill out your copyright notice in the Description page of Project Settings.

#include "LordsOfCaladanFunctionLibrary.h"

FString ULordsOfCaladanFunctionLibrary::GetPlayerStartType(class APlayerStart* playerStart)
{
	FString retString = "";
	FString PlStartName = playerStart->UObjectBaseUtility::GetName();
	if (PlStartName.Contains("Ally"))
	{
		retString = "Ally";
	}
	else if (PlStartName.Contains("Enemy"))
	{
		retString = "Enemy";
	}
	return retString;
}



float ULordsOfCaladanFunctionLibrary::ClampFloat(float MustClamp, float Min, float Max)
{
	float retFloat = MustClamp;
	if (retFloat > Max)
	{
		retFloat = Max;
	}
	else if (retFloat < Min)
	{
		retFloat = Min;
	}
	return retFloat;
}
