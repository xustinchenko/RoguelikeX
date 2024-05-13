// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Components/CapsuleComponent.h"
#include "AbilitySystemComponent.h"
#include "RoguelikeX/AbilitySystem/Base/BasicAttributeSet.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
}



