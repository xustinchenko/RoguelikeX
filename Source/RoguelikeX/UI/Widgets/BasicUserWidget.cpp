// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicUserWidget.h"

void UBasicUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}