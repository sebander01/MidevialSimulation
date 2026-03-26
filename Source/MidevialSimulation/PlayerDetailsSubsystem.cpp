// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDetailsSubsystem.h"

// Sets default values
UPlayerDetailsSubsystem::UPlayerDetailsSubsystem()
{

}

void UPlayerDetailsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UPlayerDetailsSubsystem::Deinitialize()
{
	//Resource managment
	Super::Deinitialize();
}

#pragma region Getters
//Getters for all the different resources
float UPlayerDetailsSubsystem::GetMoney()
{
	return playerMoney;
}

float UPlayerDetailsSubsystem::GetHunger()
{
	return playerHunger;
}

float UPlayerDetailsSubsystem::GetEnergy()
{
	return playerEnergy;
}

float UPlayerDetailsSubsystem::GetEntertainment()
{
	return playerEntertainment;
}

float UPlayerDetailsSubsystem::GetBlader()
{
	return playerBladder;
}
#pragma endregion

#pragma region Setters
//Setters for all the different resources
void UPlayerDetailsSubsystem::SetMoney(float money)
{
	playerMoney = money;
}

void UPlayerDetailsSubsystem::SetHunger(float hunger)
{
	playerHunger = hunger;
}

void UPlayerDetailsSubsystem::SetEnergy(float energy)
{
	playerEnergy = energy;
}

void UPlayerDetailsSubsystem::SetEntertainment(float entertainment)
{
	playerEntertainment = entertainment;
}

void UPlayerDetailsSubsystem::SetBlader(float blader)
{
	playerBladder = blader;
}
#pragma endregion

#pragma region AddResources
//Methods to easily add to resources
void UPlayerDetailsSubsystem::AddMoney(float money)
{
	playerMoney += money;
}

void UPlayerDetailsSubsystem::AddHunger(float hunger)
{
	playerHunger += hunger;
}

void UPlayerDetailsSubsystem::AddEnergy(float energy)
{
	playerEnergy += energy;
}

void UPlayerDetailsSubsystem::AddEntertainment(float entertainment)
{
	playerEntertainment += entertainment;
}

void UPlayerDetailsSubsystem::AddBlader(float blader)
{
	playerBladder += blader;
}
#pragma endregion

#pragma region Subtract resources
//Methods to easily take from resources
void UPlayerDetailsSubsystem::SubtractMoney(float money)
{
	playerMoney -= money;
}

void UPlayerDetailsSubsystem::SubtractHunger(float hunger)
{
	playerHunger -= hunger;
}

void UPlayerDetailsSubsystem::SubtractEnergy(float energy)
{
	playerEnergy -= energy;
}

void UPlayerDetailsSubsystem::SubtractEntertainment(float entertainment)
{
	playerEntertainment -= entertainment;
}

void UPlayerDetailsSubsystem::SubtractBlader(float blader)
{
	playerBladder -= blader;
}
#pragma endregion