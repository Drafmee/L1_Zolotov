// Fill out your copyright notice in the Description page of Project Settings.


#include "FireStormComponent.h"

void AFireStormComponent::BeginPlay()
{
    Super::BeginPlay();
    GetActorStaticMesh();
    FireStormComponentUpVector = ActorStaticMesh->GetUpVector();
    CircleStartLocation = GetActorLocation();
} 
void AFireStormComponent::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    MoveProjectile(DeltaTime);

    
}

void AFireStormComponent::MoveProjectile(float DeltaTime)
{
    RotationAngle += RotationSpeed * DeltaTime;
    if (RotationAngle >= 360.0f)
    {
		RotationAngle = 0.0f;
    }
    FVector CurrentLocation = CircleStartLocation + Radius * FVector(FMath::Cos(FMath::DegreesToRadians(RotationAngle)), FMath::Sin(FMath::DegreesToRadians(RotationAngle)), 0);
    CircleStartLocation = CircleStartLocation + FVector(0,0,ProjectileVelocity)*DeltaTime;
    SetActorLocation(CurrentLocation);
    FString Name = GetName();
	FString Poition = CurrentLocation.ToString();
	UE_LOG(LogTemp, Display, TEXT("Actor Name: %s Actor Position: %s "), *Name, *Poition);
    if(GetDistanceMoved()>=DistanceToMove)
	{
		this->Destroy();
	}
}