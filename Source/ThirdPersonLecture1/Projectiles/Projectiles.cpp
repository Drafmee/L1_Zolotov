// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles.h"

// Sets default values
AProjectiles::AProjectiles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectiles::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	GetActorStaticMesh();

	ForwVector = ActorStaticMesh->GetForwardVector();
}

// Called every frame
void AProjectiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AProjectiles::MoveProjectile(float DeltaTime)
{

}
void AProjectiles::GetActorStaticMesh()
{
	TArray<UStaticMeshComponent*> Components;

	this->GetComponents<UStaticMeshComponent>(Components);

	ActorStaticMesh = Components[0];	
}
float AProjectiles::GetDistanceMoved() 
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
