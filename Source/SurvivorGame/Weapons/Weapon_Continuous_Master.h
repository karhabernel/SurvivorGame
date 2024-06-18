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
	//todo. 지속딜, 범위 안에 있는 적을 배열에 넣고 타이머로 딜 주다가 범위 밖으로 나가면 딜 중지되게 하기
};
