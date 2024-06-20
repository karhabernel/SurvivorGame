#include "Characters/Components/StatComponent.h"

#include "Global.h"

UStatComponent::UStatComponent()
{

}


void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = GetMaxHealth();
	
}

void UStatComponent::IncreaseHealth(float InAmount)
{
}

void UStatComponent::DecreaseHealth(float InAmount)
{
	CLog::Print("DecreaseHealth");
	CurrentHealth -= InAmount;

	CLog::Print(CurrentHealth);
}

void UStatComponent::SetSpeedBonus(float InAmount)
{
}

void UStatComponent::SetLaunchValueBonus(float InAmount)
{
}

