#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVORGAME_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStatComponent();

protected:
	virtual void BeginPlay() override;

public:	
	//Getters
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurrentSpeed() { return Speed + SpeedBonus; }
	
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetMaxHealth() { return MaxHealth + HealthBonus; }
	
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetLaunchValue() { return LaunchValue + LaunchValueBonus; }
	
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetSpeedBonusAmount() { return SpeedBonus; }
	
	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetHealthBonusAmount() { return HealthBonus; }
	

	//Setters
	UFUNCTION(BlueprintCallable)
	void IncreaseHealth(float InAmount);

	UFUNCTION(BlueprintCallable)
	void DecreaseHealth(float InAmount);


	UFUNCTION(BlueprintCallable)
	void SetSpeedBonus(float InAmount);

	UFUNCTION(BlueprintCallable)
	void SetLaunchValueBonus(float InAmount);


private:
	UPROPERTY(EditAnywhere, Category = "Speed")
	float Speed = 200.f;

	UPROPERTY(EditAnywhere, Category = "Speed")
	float SpeedBonus = 0.f;
	
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 100.f;
	
	UPROPERTY(EditAnywhere, Category = "Health")
	float HealthBonus = 0.f;

	UPROPERTY(EditAnywhere, Category = "Stats")
	float LaunchValue = 25.f;

	UPROPERTY(EditAnywhere, Category = "Stats")
	float LaunchValueBonus = 0.f;

private:
	float CurrentHealth;
};
