// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spaceship.generated.h"

UCLASS()
class ASTEROIDS3D_CPP_API ASpaceship : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* ShipMesh;

	

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	int32 Health = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool Invulnerable = false;

private:

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
	void AsteroidHit();

	void ResetLevel();

};
