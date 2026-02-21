// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

void UUIManager::NativeConstruct() {
	Super::NativeConstruct();

	ResumeButton->OnClicked.AddDynamic(this, &UUIManager::OpenMenu);
}

void UUIManager::OpenMenu() {
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, TEXT("OPEN MENU"));
}
