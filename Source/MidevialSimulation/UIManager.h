// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UIManager.generated.h"


//Think of the two classes like exposed and unexposed

/**
 * Class for UIManager allowing for methods that interact only with the UI
 */
UCLASS()
class MIDEVIALSIMULATION_API UUIManager : public UUserWidget
{
	GENERATED_BODY()

public:

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void OpenMenu();

	UPROPERTY(meta = (BindWidget))
	class UButton* ResumeButton;

private:

};

/**
 * Class for UGameInstanceSubsystem allowing blue prints to be accessed anywhere
 */
UCLASS()
class MIDEVIALSIMULATION_API UUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//Contructor
	UUISubsystem();

	//Initlaization for subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;


	UFUNCTION(BlueprintCallable, Category = "UI Interface")
	//Allows the player to open the popup menu
	void OpenCloseAMenuWidget(TSubclassOf<UUserWidget> spawningWidget);

	//Currently open widget
	UUserWidget* OpenWidget;

private:

};
