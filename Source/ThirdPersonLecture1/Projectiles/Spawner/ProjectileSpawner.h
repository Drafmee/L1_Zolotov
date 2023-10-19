// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spawner.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectileSpawner.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THIRDPERSONLECTURE1_API UProjectileSpawner : public USpawner
{
	GENERATED_BODY()
	
public:
		

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AProjectiles> Fireball;

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AProjectiles> Sparks;

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AProjectiles> Firestorm;

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	FVector FireballOffset = FVector(0,0,0);

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	FVector SparksOffset = FVector(0,0,0);
	
	UPROPERTY(EditAnywhere, Category = "Projectile" )
	FVector FirestormOffset = FVector(0,0,0);
	
	virtual void SpawnProjectile(int32 Button) override;
};
