// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//must be last include


class TankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:


	

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	

	//Start tank moving the barrel so the shot would hit 
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000; //1km in cm

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
