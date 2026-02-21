
#include "PauseMenu.h"
#include "Components/ProgressBar.h"

void UPauseMenu::NativeConstruct() {
	Super::NativeConstruct();

	if (ResumeButton) {
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("FOUND"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, TEXT("NOT FOUND"));
	}

	ResumeButton->OnClicked.AddDynamic(this, &UPauseMenu::OpenMenu);
}

void UPauseMenu::OpenMenu() {
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, TEXT("OPEN MENU"));
}