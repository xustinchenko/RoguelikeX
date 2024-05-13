// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"
#include "Materials/Material.h"
#include "AbilitySystemComponent.h"
#include "RoguelikeX/AbilitySystem/Base/BasicAttributeSet.h"
#include "Engine/World.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(AbilitySystemComponent))
	{
		AttributeSet = AbilitySystemComponent->GetSet<UBasicAttributeSet>();
	}
}


