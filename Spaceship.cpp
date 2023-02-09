// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"

ASpaceship::ASpaceship()
{

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->bUsePawnControlRotation = false;
	CameraComponent->SetupAttachment(RootComponent);

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);

	// Disable gravity
	GetCharacterMovement()->GravityScale = 0.0f;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0, 0, 1));

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{

	Super::BeginPlay();
	
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	CameraComponent->SetWorldLocation(FVector(0, 0, 2500));
	CameraComponent->SetWorldRotation(FRotator(-90, 0, 0));
}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASpaceship::MoveForward(float Value)
{

	if (Value != 0.0f)
	{

		// Add movement in forward direction
		AddMovementInput(FVector(1, 0, 0), Value);

	}

}

void ASpaceship::MoveRight(float Value)
{

	if (Value != 0.0f)
	{

		// Add movement in right direction
		AddMovementInput(FVector(0, 1, 0), Value);

	}

}

void ASpaceship::AsteroidHit()
{
	if (Health == 1)
	{
		ShipMesh->SetVisibility(false);
		FTimerHandle DeathHandle;
		GetWorld()->GetTimerManager().SetTimer(DeathHandle, this, &ASpaceship::ResetLevel, 3.0f, false);
	}
	else
		Health = Health - 1;
}

void ASpaceship::ResetLevel()
{
	
}
