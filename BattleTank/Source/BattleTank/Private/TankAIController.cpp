// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController Can't find player tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController Found: %s"), *PlayerTank->GetName())
	}
}
/// get the tank that tankAIcontroller is possesing from (tank_BP > details).
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());/// we get the pawn that the player controller is possesing and treat it as a tank so that the functionality in the tank.cpp change it.
}
/// Get the Tank that the TankPlayerController is possesing from (game mode).
ATank* ATankAIController::GetPlayerTank() const
{
	/// we go to the world and get the firstplayercontroller(TankPlayerController)
	/// then we get the pawn that the first player controller is possessing from the game mode.
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn); /// this cast will fail incase of playerpawn is nullptr.
}
