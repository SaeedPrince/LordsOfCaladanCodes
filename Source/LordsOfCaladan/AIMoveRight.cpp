// Fill out your copyright notice in the Description page of Project Settings.

#include "AIMoveRight.h"

UAIMoveRight* UAIMoveRight::AIMoveRight(const UObject* WorldContextObject, APawn* Pawn, const float AcceptableDistance, const float MoveInterval, const float EndTime)
{
	UAIMoveRight* Node = NewObject<UAIMoveRight>();
	Node->WorldContextObject = WorldContextObject;
	Node->Pawn = Pawn;
	Node->AcceptableDistance = AcceptableDistance;
	Node->MoveInterval = MoveInterval;
	Node->EndTime = EndTime;
	return Node;

}

void UAIMoveRight::Activate()
{
	if (nullptr == WorldContextObject)
	{
		FFrame::KismetExecutionMessage(TEXT("Invalid WorldContextObject."), ELogVerbosity::Error);
		return;
	}
	if (Active)
	{
		FFrame::KismetExecutionMessage(TEXT("Is already running."), ELogVerbosity::Warning);
		return;
	}

	if (_IsPawnCloseToDestination())
	{
		placeOkay = true;
		_Finish();
	}
	else
	{
		FTimerHandle TimerEndTime;
		WorldContextObject->GetWorld()->GetTimerManager().SetTimer(TimerMoveControl, this, &AIMoveRight::_MoveControl, MoveInterval, true);
		WorldContextObject->GetWorld()->GetTimerManager().SetTimer(TimerEndTime, this, &AIMoveRight::_Finish, EndTime);
	}
	Active = true;
}

bool UAIMoveRight::_IsPawnCloseToDestination()
{
	bool retBool = false;

	return retBool;
}

void UAIMoveRight::_MoveControl()
{
	if (_IsPawnCloseToLocation())
	{
		placeOkay = true;
		_Finish();
	}
	else
	{
		_MoveOnePoint();
	}
}

void UAIMoveRight::_MoveOnePoint()
{
	FVector CharacterLocation = Pawn->GetActorLocation();
	FVector DistanceVector = Destination - CharacterLocation;
	Pawn->AddMovementInput(DistanceVector, 1.0f);
}

void UAIMoveRight::_Finish()
{
	WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(TimerMoveControl);
	TimerMoveControl.Invalidate();
	Finished.Broadcast(placeOkay);
	Active = false;
}