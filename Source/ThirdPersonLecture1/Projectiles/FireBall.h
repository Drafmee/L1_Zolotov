// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectiles.h"
#include "FireBall.generated.h"

UCLASS()
class THIRDPERSONLECTURE1_API AFireBall : public AProjectiles
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

	virtual void MoveProjectile(float DeltaTime) override;	
	
protected: 
	

	

};
