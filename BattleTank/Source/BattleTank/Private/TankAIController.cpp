// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}
void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	/// we go to the world and get the firstplayercontroller(TankPlayerController)
	/// then we get the pawn that the first player controller is possessing from the game mode.
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	/// we get the pawn that the player controller is possesing and treat it as a tank so that the functionality in the tank.cpp change it.
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {
		// TODO Move Towards the Player Tank.
		
		// Aim Towards The Player.
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
}
