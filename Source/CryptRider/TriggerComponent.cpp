#include "TriggerComponent.h"

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();	

    UE_LOG(LogTemp, Display, TEXT("Your message"));
}