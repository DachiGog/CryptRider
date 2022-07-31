#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();	

    UE_LOG(LogTemp, Display, TEXT("Your message"));
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

        AActor* Actor = GetAccaptableActor();
        if(Actor!=nullptr)
        {
            UE_LOG(LogTemp, Display, TEXT("Locking"));
        }
        else
        {
            UE_LOG(LogTemp, Display, TEXT("Relocking"));
        }

        
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

AActor* UTriggerComponent::GetAccaptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    
    for(auto* Actor : Actors)
    {
        if(Actor->ActorHasTag(AcceptableTag))
        {
            return Actor;
        }            
    }
    return nullptr;
}