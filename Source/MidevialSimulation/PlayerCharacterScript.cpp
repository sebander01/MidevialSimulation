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
void APlayerCharacterScript::MoveToPoint(UCameraComponent* cam, float maxClickDistance, FString tag, bool showDeveloperDebugs)
{
#pragma region Camera to world direction
	//A variable that will represent the origin of the player at present
	FVector playerOrigin;
	//The direction that player is in
	FVector direction;
	//This method finds the direction that the clicked point is in
	//This method contains finding the mouse position and because of the way we have to handle it once we do this we were able to get ride of the line we had also finding mouse position it was redudant and overwriting Deproject
	//My big misunderstanding is that I thought Deproject was fed a position and then returned a translated position that is in no way how this works this method just finds the direction of a ray cast like saying you clicked north but obviously more complex
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(playerOrigin, direction);
#pragma endregion

#pragma region DrawALineAndGetCollision

	//A variable to store our hit results
	FHitResult hit;
	//We need to take our direction and find the farthest possible point we are allowed to click since unreal needs an end to this vector.
	//This should be interupted when we cast into an object we are just saying if it's past this distance give up
	direction = playerOrigin + direction * maxClickDistance;
	//Unreal engine raycast and we are moving if we hit. Our trace starts at cameraFront because it's where our click starts from and ends at our modified direction both of these will create a ray
	//If we hit an object with our acceptable tag we move if we do not then we do not move
	if (GetWorld()->LineTraceSingleByChannel(hit, playerOrigin, direction,ECC_Visibility) && hit.GetActor()->Tags.Contains(tag))
	{

#pragma region AIMovement

		//We need to use SimpleMoveToLocation in this example because we are not able to change controller from playercontroller to a custom AIcontroller
		//Even if we could we wouldn't want to SimpleMoveToLocation is built to use playercontroller and MoveToLocation that I tried to use before is built to use and AIController exlusively.
		//Though if we ever need to use playercontroller and simplemovetolocation it is possible to delete and recreate controllers at run time and then change the controller being possessed but there is absolutely no reason to do this here

		//We move to the location of our hit this is the real position in world
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), hit.Location);

#pragma endregion
	}

#pragma region DebugSettingsInMoveToPoint
	//For debugging if we need developer debugs on
	if (showDeveloperDebugs)
	{
		PrintDebugMessage(FColor::Orange, hit.Location.ToString());
		//We debug the line so we can see it when testing
		DrawDebugLine(GetWorld(), playerOrigin, hit.Location, FColor::Red, false, 1.0f, 0, 0.5f);
	}
#pragma endregion

#pragma endregion

}
