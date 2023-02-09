// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidHandler.generated.h"

UCLASS()
class ASTEROIDS3D_CPP_API AAsteroidHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	FVector BoundsX = FVector(500, 1275, 50);
	FVector BoundsY = FVector(725, 500, 50);
	//FVector OriginA = FVector(1225, 0, 100);
	//FVector OriginB = FVector(0, 1775, 100);
	//FVector OriginC = FVector(-1225, 0, 100);
	//FVector OriginD = FVector(0, -1775, 100);

	TArray<FVector> Origins;

	FVector OriginSelected;
	FVector BoundsSelected;

	int OriginSelector;
	
	bool CanSpawn = true;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> AsteroidBP;

protected:

	void SpawnAsteroid();
	void ResetSpawner();
};
