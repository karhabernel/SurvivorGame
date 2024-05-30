#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_Overlapped_Master.generated.h"

UCLASS()
class SURVIVORGAME_API AWeapon_Overlapped_Master : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon_Overlapped_Master();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
