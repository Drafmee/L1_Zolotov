// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileTrace.h"

// Sets default values
AProjectileTrace::AProjectileTrace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileTrace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

