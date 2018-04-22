// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AIMoveRight.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAIMoveRightOutputPin);

/**
 * 
 */
UCLASS()
class LORDSOFCALADAN_API UAIMoveRight : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
		FAIMoveRightOutputPin Success;
	UPROPERTY(BlueprintAssignable)
		FAIMoveRightOutputPin Fail;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AI|Movement")
		static UAIMoveRight* AIMoveRight(const UObject* WorldContextObject, APawn* Pawn, const float MoveInterval);

	virtual void Activate() override;

private:
	UFUNCTION()
		FVector _PawnDirection();

	UFUNCTION()
		virtual void _MoveControl();

	UFUNCTION()
		virtual void _Finish();

	UFUNCTION()
		void _MoveOnePoint();

	const UObject* WorldContextObject;
	bool Active;
	bool success;
	APawn* Pawn;
	float MoveInterval;
	FTimerHandle TimerMoveControl;
	FVector StartPosition;
	FVector EndPosition;
};
