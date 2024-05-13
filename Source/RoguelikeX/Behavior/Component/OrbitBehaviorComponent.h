// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitBehaviorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROGUELIKEX_API UOrbitBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrbitBehaviorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Configurable parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orbit")
	float OrbitDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orbit")
	float OrbitPeriod;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orbit")
	AActor* CenterActor;

private:
	float OrbitPhase; // Current phase in the orbit

		
};
