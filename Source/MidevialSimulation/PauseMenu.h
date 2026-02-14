#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

UCLASS(Abstract)
class UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void OpenMenu();

	UPROPERTY(meta = (BindWidget))
	class UButton* ResumeButton;

protected:
	void NativeConstruct() override;

private:
};