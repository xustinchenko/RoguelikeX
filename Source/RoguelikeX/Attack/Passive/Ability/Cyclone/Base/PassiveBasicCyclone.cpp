// Fill out your copyright notice in the Description page of Project Settings.


#include "PassiveBasicCyclone.h"
#include "RoguelikeX/Behavior/Component/OrbitBehaviorComponent.h"

// Sets default values
APassiveBasicCyclone::APassiveBasicCyclone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OrbitBehaviorComponent = CreateDefaultSubobject<UOrbitBehaviorComponent>(TEXT("OrbitBehaviorComponent"));
}