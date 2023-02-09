// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AsteroidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AsteroidMesh"));
	AsteroidMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AAsteroid::OnConstruction(const FTransform& Transform)
{
	if (Meshes.Num() > 0)
		AsteroidMesh->SetStaticMesh(Meshes[FMath::RandRange(0, Meshes.Num() - 1)]);
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();

	

	RPoint = UKismetMathLibrary::RandomPointInBoundingBox(FVector( 0, 0, 100), FVector(725, 1275, 50));
	UE_LOG(LogTemp, Warning, TEXT("Random Point %s"), *RPoint.ToString());
	NRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), RPoint);
	if (this->SetActorRotation(NRotation))
		canMove = true;

}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (canMove)
	{
		this->SetActorLocation(this->GetActorLocation() + (this->GetActorForwardVector() * Speed));
		this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y, 50));
	}

	AsteroidMesh->AddRelativeRotation(RotationRate);
}

void AAsteroid::TakeHit()
{
	if (Health == 1)
	{
		Destroy();
	}
	else
		Health = Health - 1;
}

