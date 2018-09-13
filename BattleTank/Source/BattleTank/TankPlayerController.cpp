// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

/// get the tank that tankplayercontroller is a parent of the (TankPlayerController_BP)
/// that possesing from (the game mode).
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); /// we get the pawn that the player controller is possesing and treat it as a tank so that the functionality in the tank.cpp change it.
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT Parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-Effect", is going to linetrace
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
			//TODO tell controlled tank to aim at this point
	}
}
// Get World location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find The crosshair postion in pixel coordinates.
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY); // we are getting the X and Y size of the screen(Out Parameters).
	FVector2D AimLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	// "de-project" the screen position of the crosshair to a world direction.
	
	FVector LookDirection;
	if (GetLookDirection(AimLocation, LookDirection)) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *LookDirection.ToString())
	}
	// Line-trace along that LookDirection, and see what we hit (up to max).
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D & AimLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation; // To Be Discarded
	return DeprojectScreenPositionToWorld(	// Location And Direction are OUT Parameters.
		AimLocation.X,
		AimLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

