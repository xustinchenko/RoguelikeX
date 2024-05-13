// Fill out your copyright notice in the Description page of Project Settings.


#include "PassiveOverlapAttack.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APassiveOverlapAttack::APassiveOverlapAttack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup collision mesh
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;
	
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionMesh"));
	CollisionMesh->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SetupCollision();
}

// Called when the game starts or when spawned
void APassiveOverlapAttack::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APassiveOverlapAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void APassiveOverlapAttack::SetupCollision()
{
	CollisionMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CollisionMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_EngineTraceChannel1, ECR_Overlap);
}


