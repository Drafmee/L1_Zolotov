// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ThirdPersonLecture1Character.generated.h"


UCLASS(config=Game)
class AThirdPersonLecture1Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* FireFireballAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* FireSparksAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* FireFirestormAction;

public:
	AThirdPersonLecture1Character();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AActor> Fireball;

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AActor> Sparks;

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	TSubclassOf<class AActor> Firestorm;

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void FireFireball();

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void FireSparks();

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void FireFirestorm();

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	FVector FireballOffset = FVector(0,0,0);

	UPROPERTY(EditAnywhere, Category = "Projectile" )
	FVector SparksOffset = FVector(0,0,0);
	
	UPROPERTY(EditAnywhere, Category = "Projectile" )
	FVector FirestormOffset = FVector(0,0,0);
	
};

