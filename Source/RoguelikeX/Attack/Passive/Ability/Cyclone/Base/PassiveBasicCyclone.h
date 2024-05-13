// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoguelikeX/Attack/Passive/Base/PassiveOverlapAttack.h"
#include "PassiveBasicCyclone.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIKEX_API APassiveBasicCyclone : public APassiveOverlapAttack
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	APassiveBasicCyclone();

public:	
	// Weapon's behavior component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UOrbitBehaviorComponent* OrbitBehaviorComponent;
	
};
