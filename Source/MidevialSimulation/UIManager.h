// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class MIDEVIALSIMULATION_API UUIManager : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OpenMenu();

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* ResumeButton;

private:
	
};
