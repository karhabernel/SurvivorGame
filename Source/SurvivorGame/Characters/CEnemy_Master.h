#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CEnemy_Master.generated.h"

UCLASS()
class SURVIVORGAME_API ACEnemy_Master : public ACharacter
{
	GENERATED_BODY()
	
public:	
	ACEnemy_Master();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void BeHitted(float InDamage, AActor* DamageCauser);
};
