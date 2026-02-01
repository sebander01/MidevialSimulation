// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterScript.h"

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

void APlayerCharacterScript::MoveToPoint()
{

}
