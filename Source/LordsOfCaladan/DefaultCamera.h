// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DefaultCamera.generated.h"

UCLASS()
class LORDSOFCALADAN_API ADefaultCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADefaultCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
