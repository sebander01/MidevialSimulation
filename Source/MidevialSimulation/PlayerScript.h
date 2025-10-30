// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerScript.generated.h"

UCLASS()
class MIDEVIALSIMULATION_API APlayerScript : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerScript();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "PlayerMovement")
	//Allows the player to move to a point clicked on the ground by a players mouse
	void MoveToPoint();

};
