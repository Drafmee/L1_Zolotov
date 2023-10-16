// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"
#include "FireBall.generated.h"

UCLASS()
class THIRDPERSONLECTURE1_API AFireBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected: 
	UPROPERTY(EditAnywhere, Category = "Projectile")	
	float ProjectileVelocity = 100.0f;
	
	FVector StartLocation;

	FVector CharacterAdjustment;

	FVector ForwVector;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float DistanceToMove = 10000.0f;

	float GetDistanceMoved();	

	UStaticMeshComponent* ActorStaticMesh;

	void GetActorStaticMesh();

	UPROPERTY(EditAnywhere, Category = "Projectile")	
	float StepDistance = 100.0f;

private:
	void MoveProjectile(float DeltaTime);	
	

};
