// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UBasicUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;
/**
 * 
 */


UCLASS()
class ROGUELIKEX_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	TObjectPtr<UBasicUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	UFUNCTION(BlueprintCallable)
	void InitOverlay(APlayerController* PC, UAbilitySystemComponent* ASC , UAttributeSet* AS);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBasicUserWidget> OverlayWidgetClass;

	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};

