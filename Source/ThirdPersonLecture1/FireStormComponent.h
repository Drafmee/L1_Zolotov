// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FireBall.h"
#include "FireStormComponent.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONLECTURE1_API AFireStormComponent : public AFireBall
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Radius= 100.0f;

	// Speed of rotation
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed= 45.0f;	

	float RotationAngle;

	FVector FireStormComponentUpVector;

	FVector CircleStartLocation;

private:
	void MoveFireStormComponent(float DeltaTime);		
};
