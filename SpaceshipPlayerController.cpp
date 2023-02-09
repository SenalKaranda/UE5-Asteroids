// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipPlayerController.h"
#include "Camera/CameraComponent.h"

void ASpaceshipPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Get the controlled pawn
	AActor* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		// Set view target to the camera component of the spaceship
		SetViewTarget(ControlledPawn);
	}

	
}
