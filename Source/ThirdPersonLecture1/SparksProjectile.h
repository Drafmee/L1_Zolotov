// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FireBall.h"
#include "SparksProjectile.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONLECTURE1_API ASparksProjectile : public AFireBall
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(EditAnywhere, Category = "Projectile")
	float ShiftOnY = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float ShiftOnX = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float Amplitude = 4.5f;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float Frequency = 10.0f;

	FVector ProjectileUpVector;

	float CurrentTime;
	
private:
	void MoveProjectileSparks(float DeltaTime);
};
