// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class ASTEROIDS3D_CPP_API AAsteroid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	FVector RPoint;
	FVector Dir = RPoint - GetActorLocation();
	FVector NDir = Dir.GetSafeNormal();
	FRotator NRotation = NDir.Rotation();

	bool canMove = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* AsteroidMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UStaticMesh*> Meshes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRotator RotationRate;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 Health = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 Speed = 3;

	UFUNCTION(BlueprintCallable)
	void TakeHit();

};
