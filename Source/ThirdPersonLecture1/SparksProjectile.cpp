// Fill out your copyright notice in the Description page of Project Settings.


#include "SparksProjectile.h"




void ASparksProjectile::BeginPlay()
{
    Super::BeginPlay();
    
    GetActorStaticMesh();

    ProjectileUpVector = ActorStaticMesh->GetUpVector(); 
    ForwVector = ActorStaticMesh->GetForwardVector();

    FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);


}
void ASparksProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    MoveProjectileSparks(DeltaTime);
    
}

void ASparksProjectile:: MoveProjectileSparks(float DeltaTime)
{
  //  Y=a+b*sin(c*X+d)
   // UE_LOG(LogTemp, Display, TEXT("BeginPlay: calling tick "));
    FVector CurrentLocation = GetActorLocation();           
	CurrentLocation = CurrentLocation + (ForwVector * ProjectileVelocity * DeltaTime) + ((ShiftOnY + Amplitude * FMath::Sin(Frequency * CurrentTime + ShiftOnX)) * ProjectileUpVector);
	SetActorLocation(CurrentLocation);
    FString Name = GetName();
	FString Poition = CurrentLocation.ToString();
	UE_LOG(LogTemp, Display, TEXT("Actor Name: %s Actor Position: %s "), *Name, *Poition);
	CurrentTime += DeltaTime;
    if(GetDistanceMoved()>=DistanceToMove)
	{
		this->Destroy();
	}


}