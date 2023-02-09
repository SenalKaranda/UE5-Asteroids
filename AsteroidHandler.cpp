// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidHandler.h"
#include "Asteroid.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAsteroidHandler::AAsteroidHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Origins.Add(FVector(1950, 0, 100));
	Origins.Add(FVector(0, 3050, 100));
	Origins.Add(FVector(-1950, 0, 100));
	Origins.Add(FVector(0, -3050, 100));
}

// Called when the game starts or when spawned
void AAsteroidHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsteroidHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CanSpawn)
		SpawnAsteroid();
}

void AAsteroidHandler::SpawnAsteroid()
{
	CanSpawn = false;

	OriginSelector = FMath::RandRange(2, 5);
	OriginSelected = Origins[OriginSelector - 2];
	
	if ((OriginSelector % 2) == 0)
	{
		BoundsSelected = FVector(500, 1275, 50);
	}
	else
	{
		BoundsSelected = FVector(725, 500, 50);
	}

	FVector SpawnLoc = UKismetMathLibrary::RandomPointInBoundingBox(OriginSelected, BoundsSelected);
	FRotator SpawnRot(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	GetWorld()->SpawnActor<AAsteroid>(AsteroidBP, SpawnLoc, SpawnRot, SpawnInfo);

	FTimerHandle SpawnAsteroidHandle;
	GetWorld()->GetTimerManager().SetTimer(SpawnAsteroidHandle, this, &AAsteroidHandler::ResetSpawner, 5.0f, false);

}

void AAsteroidHandler::ResetSpawner()
{
	CanSpawn = true;
}
