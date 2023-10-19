// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileTrace.generated.h"

UCLASS()
class THIRDPERSONLECTURE1_API AProjectileTrace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileTrace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AActor> Projectile;
};
