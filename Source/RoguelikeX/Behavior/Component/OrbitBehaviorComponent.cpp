// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitBehaviorComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UOrbitBehaviorComponent::UOrbitBehaviorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	OrbitDistance = 300.0f;
	OrbitPeriod = 2.0f;
	OrbitPhase = 0.0f;
}


// Called when the game starts
void UOrbitBehaviorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitBehaviorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CenterActor)
	{
		// Update position
		OrbitPhase += DeltaTime * (2 * PI / OrbitPeriod);
		OrbitPhase = FMath::Fmod(OrbitPhase, 2 * PI);

		FVector CenterLocation = CenterActor->GetActorLocation();
		FVector OrbitLocation = CenterLocation + OrbitDistance * FVector(FMath::Cos(OrbitPhase), FMath::Sin(OrbitPhase), 0.0f);
		GetOwner()->SetActorLocation(OrbitLocation);

		// Update rotation to face the center
		FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), CenterLocation);
		GetOwner()->SetActorRotation(NewRotation);

		// Alternatively, update rotation to face the direction of travel
		FVector PreviousLocation = GetOwner()->GetActorLocation();
		if (!PreviousLocation.Equals(OrbitLocation, 0.1f)) { // Check to avoid division by zero or unnecessary calculations
			FRotator TravelDirection = UKismetMathLibrary::FindLookAtRotation(PreviousLocation, OrbitLocation);
			GetOwner()->SetActorRotation(TravelDirection);
		}
	}
}

