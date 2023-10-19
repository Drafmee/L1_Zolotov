// Fill out your copyright notice in the Description page of Project Settings.


#include "FireBall.h"

// Sets default values
AFireBall::AFireBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFireBall::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);

	GetActorStaticMesh();

	ForwVector = ActorStaticMesh->GetForwardVector();

	
}

// Called every frame
void AFireBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveProjectile(DeltaTime);
}

void AFireBall::MoveProjectile(float DeltaTime)
{	
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (ForwVector * ProjectileVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	FString Name = GetName();
	FString Poition = CurrentLocation.ToString();
	UE_LOG(LogTemp, Display, TEXT("Actor Name: %s Actor Position: %s "), *Name, *Poition);

	if(GetDistanceMoved()>=DistanceToMove)
	{
		this->Destroy();
	}

}

