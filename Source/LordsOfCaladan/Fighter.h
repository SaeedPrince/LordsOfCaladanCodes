// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Fighter.generated.h"

UCLASS()
class LORDSOFCALADAN_API AFighter : public ACharacter
{
	GENERATED_BODY()

	/** Sword collision */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* Sword;

public:
	// Sets default values for this character's properties
	AFighter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Fighter|Type")
		FString GetType();

	UFUNCTION(BlueprintPure, Category = "Fighter|Runner")
		FString GetRunner();

	UFUNCTION(BlueprintCallable, Category = "Fighter|Type")
		void SetType(FString TypeToSet);

	UFUNCTION(BlueprintCallable, Category = "Fighter|Runner")
		void SetRunner(FString RunnerToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

private:
	// Variables
	FString Type;
	FString Runner;

};
