#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Weapon_Continuous_Master.h"
#include "Weapon_Overlapped_Master.h"

#include "Weapon_DataAsset.generated.h"

//------------------------------------------------------------------------------------------------
// WeaponData
//------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct FOverlappedWeaponDataType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	AWeapon_Overlapped_Master* weapon;

	UPROPERTY(EditAnywhere)
	float PlayRate = 1.f;

	UPROPERTY(EditAnywhere)
	float FireRate;

	// 발사 수
	UPROPERTY(EditAnywhere)
	int32 AmmunitionAmount;

	//만약 회전 시, 회전 속도
	UPROPERTY(EditAnywhere)
	float RotationSpeed;
};

UCLASS()
class SURVIVORGAME_API UWeapon_DataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Equipment")
	FOverlappedWeaponDataType OverlapWeaponData;
};
