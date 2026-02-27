// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "Kismet//GameplayStatics.h"

void UUIManager::NativeConstruct() {
	Super::NativeConstruct();

	SetKeyboardFocus();
	ResumeButton->OnClicked.AddDynamic(this, &UUIManager::OpenMenu);
}

void UUIManager::OpenMenu() {
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, TEXT("OPEN MENU"));
}




#pragma region UISubsystem
//https://tech.flying-rat.studio/ue-subsystems-x3n8v5q2?utm_source=chatgpt.com#subsystems-lifetime-overview is a useful resource in learning this
UUISubsystem::UUISubsystem()
{
	//Constructor for any internal data
}

void UUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UUISubsystem::Deinitialize()
{
	//Resource managment
	Super::Deinitialize();
}
#pragma endregion

/// <summary>
/// Allows the player to open the widget for a given menu
/// </summary>
void UUISubsystem::OpenCloseAMenuWidget(TSubclassOf<UUserWidget> spawningWidget)
{
	//If the widget exists
	if (!OpenWidget)
	{
		//Create a user widget and save it to OpenWidget
		OpenWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), spawningWidget);
		//Add user widget to view port
		OpenWidget->AddToViewport();
		//Change game mode and set input gamemode ui focus
		FInputModeGameAndUI input;
		input.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(input);
	}
	else
	{
		//Change game mode and set input gamemode ui focus null
		//Note when we add buttons in regular play this should set focus back to that widget
		FInputModeGameAndUI input;
		input.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(input);
		//Remove from parent including view port.
		//RemoveFromViewport() is depreciated and incompable with later unreal versions according to unreals warning.
		OpenWidget->RemoveFromParent();
		//Nullify it for absolute garbage collection deletion
		OpenWidget = nullptr;
	}
}
