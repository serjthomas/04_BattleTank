// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing the Tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesing: %s"), *ControlledTank->GetName())
	}
}

/// get the tank that tankplayercontroller is a parent of the (TankPlayerController_BP)
/// that possesing from (the game mode).
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); /// we get the pawn that the player controller is possesing and treat it as a tank so that the functionality in the tank.cpp change it.
}

