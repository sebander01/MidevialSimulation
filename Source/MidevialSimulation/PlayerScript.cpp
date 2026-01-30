// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerScript.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
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
	//On begin we have to give the AI controller a controller
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

/// <summary>
/// We should delete this before release but this method allows us to use AddOnScreenDebugMessage in a way that isn't super annoying to use
/// </summary>
/// <param name="color"></param>
/// <param name="text"></param>
void PrintDebugMessage(FColor color, FString TEXT(text))
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, color, TEXT(text));
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
	FVector destination(mouse.X, mouse.Y, maxClickDistance);
	//This method translates the mouse position without this it's off by alot.
	//The following are like foot notes based on what I learned while figuring this out:
	//It requires us to add #include gameframework/PlayerController.h and somewhere we have to also get our first person controller GetWorld()->GetFirstPlayerController()->DeprojectMouse.. works great
	//note for if we reuse this in other projects or just for later if we start needing to get player controller even twice we should throw GetWorld()->GetFirstPlayerController() into a PlayerController* variable
	//but right now we have no need to store it.
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(destination, cameraFront);
	//This method seems to translate destination so from this point on destination seems to be accurate and can just be used below with 0 issues because it's been modified.
	DrawDebugLine(GetWorld(), cameraFront, destination, FColor::Red, false, 1.0f, 0, 0.5f);
#pragma endregion

#pragma region Ai Controller and Movement

	//Get the AI controller
	MyAiController = Cast<AMyAIController>(GetController());
	if (MyAiController)
	{
		PrintDebugMessage(FColor::Green, "Not Null");
		//Then it has to possess the player object
		MyAiController->Possess(this);

		//We move to location using the following a destination, radius and allowincompletepaths selected by the dev in blueprint
		//We assume always that overlap, pathfinding and project destination in that order are true but in this game we do not want to allow strafing
		//We also assume we want to use nav mesh filter 0 for default
		MyAiController->MoveToLocation(destination, radius, true, true, true, false, 0, allowIncompletePaths);
	}
	else
	{
		PrintDebugMessage(FColor::Red, "Null");
	}
		
#pragma endregion
}

