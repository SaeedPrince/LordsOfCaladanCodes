// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Human.generated.h"

UCLASS()
class LORDSOFCALADAN_API AHuman : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHuman();

	// Getters
	UFUNCTION(BlueprintPure, Category = "Human|Role")
		FString GetRole();

	UFUNCTION(BlueprintPure, Category = "Human|Appearance|Chest")
		int GetChestType();

	UFUNCTION(BlueprintPure, Category = "Human|Appearance|Chest")
		int GetChestModel();

	UFUNCTION(BlueprintPure, Category = "Human|Appearance|Chest")
		int GetChestMaterial();

	UFUNCTION(BlueprintPure, Category = "Human|Appearance|Chest")
		int GetSkirtMaterial();

	// Setters
	UFUNCTION(BlueprintCallable, Category = "Human|Role")
		void SetRole(FString RoleToSet);

	UFUNCTION(BlueprintCallable, Category = "Human|Appearance|Chest")
		void SetChestType(int ChestTypeToSet);

	UFUNCTION(BlueprintCallable, Category = "Human|Appearance|Chest")
		void SetChestModel(int ChestModelToSet);

	UFUNCTION(BlueprintCallable, Category = "Human|Appearance|Chest")
		void SetChestMaterial(int ChestMaterialToSet);

	UFUNCTION(BlueprintCallable, Category = "Human|Appearance|Chest")
		void SetSkirtMaterial(int SkirtMaterialToSet);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FString Role;
	int ChestType;
	int ChestModel;
	int ChestMaterial;
	int SkirtMaterial;
	
};
