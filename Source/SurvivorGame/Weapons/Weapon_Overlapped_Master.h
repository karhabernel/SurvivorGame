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
	// todo. 충돌하면 딜을 주는 타입. 일반적인 탄환과 같은 투사체와 검 등을 포함. 같은 적이 다중 타격을 맞지 않도록 처리할것

	//FUNCTIONS
public:
	//FUNCTIONS
	UFUNCTION()
	void OnAttachmentBeginOverlap(class UPrimitiveComponent* InOverlappedComponent, class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter);
	
	UFUNCTION()
	void OnAttachmentEndOverlap(class UPrimitiveComponent* InOverlappedComponent, class ACharacter* InAttacker, class AActor* InCauser, class ACharacter* InOtherCharacter);

	//INLINES
public:
	//clear hitted actors
	FORCEINLINE void ClearHittedCharacters() { HittedCharacters.Empty(); }

private:
	UPROPERTY(EditDefaultsOnly)
	class UWeapon_DataAsset* DataAsset;

private:
	TArray<class ACharacter*> HittedCharacters;
};
