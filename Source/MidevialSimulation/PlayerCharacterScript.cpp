// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterScript.h"
#include "Camera/CameraComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

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
/// We should delete this before release but this method allows us to use AddOnScreenDebugMessage in a way that isn't super annoying to use
/// </summary>
/// <param name="color"></param>
/// <param name="text"></param>
void PrintDebugMessage(FColor color, FString TEXT(text))
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, color, TEXT(text));
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

		//We need to use SimpleMoveToLocation in this example because we are not able to change controller from playercontroller to AIcontroller
		//Even if we could we wouldn't want to SimpleMoveToLocation is built to use playercontroller and MoveToLocation that I tried to use before is built
		//To use and AI controller exclusively.

		//Important in the future for me to remember you can only have 1 active controller at a time. It's possible to effective delete a controller and make a new one at run time (I think)
		//But we don't want to do that here because we have no extra code we are running where we need our own AI class for this I am just kind of making a foot note that is a much more complicated but possible option
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), destination);
#pragma endregion

}
