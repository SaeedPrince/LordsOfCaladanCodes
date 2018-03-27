// Fill out your copyright notice in the Description page of Project Settings.

#include "Human.h"


// Sets default values
AHuman::AHuman()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Role = "Idle";
	ChestType = 0;
	ChestModel = 4;
	ChestMaterial = 8;
	SkirtMaterial = 9;
}

// Called when the game starts or when spawned
void AHuman::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHuman::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Getters
FString AHuman::GetRole()
{
	return Role;
}

int AHuman::GetChestType()
{
	return ChestType;
}

int AHuman::GetChestModel()
{
	return ChestModel;
}

int AHuman::GetChestMaterial()
{
	return ChestMaterial;
}

int AHuman::GetSkirtMaterial()
{
	return SkirtMaterial;
}

// Setters
void AHuman::SetRole(FString RoleToSet)
{
	Role = RoleToSet;
}

void AHuman::SetChestType(int ChestTypeToSet)
{
	ChestType = ChestTypeToSet;
}

void AHuman::SetChestModel(int ChestModelToSet)
{
	ChestModel = ChestModelToSet;
}

void AHuman::SetChestMaterial(int ChestMaterialToSet)
{
	ChestMaterial = ChestMaterialToSet;
}

void AHuman::SetSkirtMaterial(int SkirtMaterialToSet)
{
	SkirtMaterial = SkirtMaterialToSet;
}


