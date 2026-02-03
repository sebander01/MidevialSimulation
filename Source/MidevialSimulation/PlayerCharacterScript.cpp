// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterScript.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacterScript::APlayerCharacterScript()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacterScript::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacterScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacterScript::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/// <summary>
/// A method to move the player to a point using nav mesh
/// </summary>
/// <param name="cam"></param>
/// <param name="maxClickDistance"></param>
void APlayerCharacterScript::MoveToPoint(UCameraComponent* cam, float maxClickDistance)
{
#pragma region Camera to world location
	//Collect the front of the camera
	FVector cameraFront = cam->GetForwardVector();
	//The value of the mouse position
	FVector2D mouse;
	//Get the mouse position and store it in mouse
	GEngine->GameViewport->GetMousePosition(mouse);
	//Make a 3D vector that will be used as destination later
	FVector destination(mouse.X, mouse.Y, maxClickDistance);
	//This method translates the mouse position without this it's off by alot.
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(destination, cameraFront);
	//This method seems to translate destination so from this point on destination seems to be accurate and can just be used below with 0 issues because it's been modified.
	//We debug the line so we can see it
	DrawDebugLine(GetWorld(), cameraFront, destination, FColor::Red, false, 1.0f, 0, 0.5f);
#pragma endregion

#pragma region AIMovement

#pragma endregion

}
