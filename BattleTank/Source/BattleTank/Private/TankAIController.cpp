// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include"TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
		//TODO Move torwards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check Radius si in cm
		//Aim towards to playe

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());


		//ControlledTank->Fire(); //TODO don t fire very frame

	
}



