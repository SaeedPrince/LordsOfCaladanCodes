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

FTransform ULordsOfCaladanFunctionLibrary::MakeSpawnTransform(class AActor* InputActor)
{
	FTransform retTransform;
	FVector ActorLocation = InputActor->GetActorLocation();
	FRotator ActorRotation = InputActor->GetActorRotation();
	FQuat ActorQuaternion = FQuat(ActorRotation);
	retTransform.SetLocation(ActorLocation);
	retTransform.SetRotation(ActorQuaternion);
	return retTransform;
}

FRotator ULordsOfCaladanFunctionLibrary::MakeRotatorByZ(FRotator InputRotator)
{
	FRotator retRotator;
	retRotator.Yaw = InputRotator.Yaw;
	return retRotator;
}

FVector ULordsOfCaladanFunctionLibrary::GetForwardVector(FRotator InRot)
{
	return FRotationMatrix(InRot).GetScaledAxis(EAxis::X);
}

FVector ULordsOfCaladanFunctionLibrary::GetRightVector(FRotator InRot)
{
	return FRotationMatrix(InRot).GetScaledAxis(EAxis::Y);
}

FVector ULordsOfCaladanFunctionLibrary::GetMovementVector(FRotator InputRotator, FString Direction)
{
	FVector retVector;
	if (Direction == "Forward")
	{
		retVector = GetForwardVector(InputRotator);
	}
	else if (Direction == "Right")
	{
		retVector = GetRightVector(InputRotator);
	}
	return retVector;
}

FDateTime ULordsOfCaladanFunctionLibrary::AddOneScaledSecond(FDateTime InputTime)
{
	FDateTime retDateTime = InputTime;
	FTimespan timeAdd;
	int32 theHour;
	int32 DayTimeScale = 144;
	int32 NightTimeScale = 288;
	theHour = InputTime.GetHour();
	if (theHour < 7 || theHour > 17)
	{
		timeAdd = FTimespan(0, 0, NightTimeScale);
	}
	else
	{
		timeAdd = FTimespan(0, 0, DayTimeScale);
	}
	retDateTime += timeAdd;
	return retDateTime;
}
