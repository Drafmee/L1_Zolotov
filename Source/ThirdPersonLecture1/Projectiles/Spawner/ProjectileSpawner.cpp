// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSpawner.h"





void UProjectileSpawner::SpawnProjectile(int32 Button)
{
switch ( Button )
      {
         case 1:
         {
            FVector ProjectileOffset = FireballOffset;
	        if (Fireball != nullptr)
	        {	
		        UWorld* const World = GetWorld();
		        if (World != nullptr)
		            {
			        //APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			        //const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();

			        const FRotator SpawnRotation =GetOwner()->GetActorRotation();
			        // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			        const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(ProjectileOffset);
	
			        //Set Spawn Collision Handling Override
			        FActorSpawnParameters ActorSpawnParams;
			        ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
			        // Spawn the projectile at the muzzle
			        World->SpawnActor<AProjectiles>(Fireball, SpawnLocation, SpawnRotation, ActorSpawnParams);
		            }	

	        }
         }
            break;
         case 2:
            {
                FVector ProjectileOffset = SparksOffset;
	                if (Sparks != nullptr)
	                {	
		                UWorld* const World = GetWorld();
		                if (World != nullptr)
		                {
			            //APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			            //const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();

			            const FRotator SpawnRotation =GetOwner()->GetActorRotation();
			            // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			            const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(ProjectileOffset);
	
			            //Set Spawn Collision Handling Override
			            FActorSpawnParameters ActorSpawnParams;
			            ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
			            // Spawn the projectile at the muzzle
			            World->SpawnActor<AProjectiles>(Sparks, SpawnLocation, SpawnRotation, ActorSpawnParams);
		                }	

	                }
            }
            break;
         case 3:
            {
                FVector ProjectileOffset = FirestormOffset;
	                if (Firestorm != nullptr)
	                {	
		                UWorld* const World = GetWorld();
		                if (World != nullptr)
		                {
			            //APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			            //const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();

			            const FRotator SpawnRotation =GetOwner()->GetActorRotation();
			            // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			            const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(ProjectileOffset);
	
			            //Set Spawn Collision Handling Override
			            FActorSpawnParameters ActorSpawnParams;
			            ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;    
			            // Spawn the projectile at the muzzle
			            World->SpawnActor<AProjectiles>(Firestorm, SpawnLocation, SpawnRotation, ActorSpawnParams);
		                }	

	                }
            }
            break;
         default:
            break;
      }
}