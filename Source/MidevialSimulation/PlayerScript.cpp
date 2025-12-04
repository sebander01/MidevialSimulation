// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerScript.h"
#include "Camera/CameraComponent.h"
#include "MyAIController.h"


// Sets default values
APlayerScript::APlayerScript()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerScript::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerScript::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerScript::ToPointOnClick(UCameraComponent* cam, float maxClickDistance, float radius, bool allowIncompletePaths)
{
#pragma region Camera to world location
	//Collect the front of the camera
	FVector cameraFront = cam->GetForwardVector();
	//The value of the mouse position
	FVector2D mouse;
	//Get the mouse position and store it in mouse
	GEngine->GameViewport->GetMousePosition(mouse);
	//Make a 3D vector that will be used as destination later
	FVector destination(maxClickDistance, mouse.X, mouse.Y);
#pragma endregion

#pragma region Ai Controller and Movement
	//Retrieve our AI controller and store it as MyAiController we will use this below
	AMyAIController* MyAiController = Cast<AMyAIController>(GetController());

	//We move to location using the following a destination, radius and allowincompletepaths selected by the dev in blueprint
	//We assume always that overlap, pathfinding and project destination in that order are true but in this game we do not want to allow strafing
	//We also assume we want to use nav mesh filter 0 for default
	MyAiController->MoveToLocation(destination, radius, true, true, true, false, 0, allowIncompletePaths);
#pragma endregion
}

