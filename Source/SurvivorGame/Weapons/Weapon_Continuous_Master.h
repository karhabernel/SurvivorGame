#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_Continuous_Master.generated.h"

UCLASS()
class SURVIVORGAME_API AWeapon_Continuous_Master : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon_Continuous_Master();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
