// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle) {
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f!"), *Name, Throttle)
	// TODO clamp actual throttle value so player can't over-drive.

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); // we can't add forces to a (SceneComponent). so we need to cast it to a (UPrimitiveComponent).
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}