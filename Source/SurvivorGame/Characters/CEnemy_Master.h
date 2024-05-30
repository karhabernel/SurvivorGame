#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CEnemy_Master.generated.h"

UCLASS()
class SURVIVORGAME_API ACEnemy_Master : public AActor
{
	GENERATED_BODY()
	
public:	
	ACEnemy_Master();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
