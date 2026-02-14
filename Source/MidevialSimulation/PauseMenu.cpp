
#include "PauseMenu.h"
#include "Components/ProgressBar.h"

void UPauseMenu::NativeConstruct() {
	Super::NativeConstruct();

	//ResumeButton->OnClicked.AddUniqueDynamic(this, &UPauseMenu::OpenMenu);
}

void UPauseMenu::OpenMenu() {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Menu Opened"));
	}
}