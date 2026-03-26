// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerDetailsSubsystem.generated.h"

UCLASS()
class MIDEVIALSIMULATION_API UPlayerDetailsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	UPlayerDetailsSubsystem();

protected:

public:	

	//Initlaization for subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	//Getters
	float GetMoney();
	float GetHunger();
	float GetEnergy();
	float GetEntertainment();
	float GetBlader();

	//Setters
	void SetMoney(float money);
	void SetHunger(float hunger);
	void SetEnergy(float energy);
	void SetEntertainment(float entertainment);
	void SetBlader(float blader);

	//Add
	void AddMoney(float money);
	void AddHunger(float hunger);
	void AddEnergy(float energy);
	void AddEntertainment(float entertainment);
	void AddBlader(float blader);

	//Subtract
	void SubtractMoney(float money);
	void SubtractHunger(float hunger);
	void SubtractEnergy(float energy);
	void SubtractEntertainment(float entertainment);
	void SubtractBlader(float blader);
protected:
	float playerMoney;
	float playerHunger;
	float playerEnergy;
	float playerEntertainment;
	float playerBladder;
};
