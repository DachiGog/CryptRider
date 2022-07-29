// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h" 

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UWorld *World = GetWorld();

	FVector Start = GetComponentLocation();
	FVector forward = GetForwardVector();
	FVector End = Start + forward * MaxGrabDistance;
	DrawDebugLine(World, Start, End, FColor::Red);

	float Damage = 5;
	PrintDamage(Damage);
	UE_LOG(LogTemp, Display, TEXT("Your message%f"), Damage);

}

void UGrabber::PrintDamage(float& Damage)
{
	Damage = 2;
	UE_LOG(LogTemp, Display, TEXT("Your message%f"), Damage);
}

