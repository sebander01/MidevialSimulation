#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PauseMenu.generated.h"

UCLASS(Abstract)
class UPauseMenu : public UUserWidget
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