// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoguelikeX/Character/BaseCharacter.h"
#include "EnemyBase.generated.h"

UCLASS()
class ROGUELIKEX_API AEnemyBase : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
