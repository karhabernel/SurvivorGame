#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CPlayer.generated.h"

UCLASS()
class SURVIVORGAME_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

//----------------------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------------------
// Inputs
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* EvadeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* PlayerSkill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* Menu;



	// Input Functions
protected:
	void Move(const FInputActionValue& Value);
	void Evade(const FInputActionValue& Value);
	void OnSkill(const FInputActionValue& Value);
	void OnMenu(const FInputActionValue& Value);

	//Scene Component
private:
	UPROPERTY(VisibleDefaultsOnly)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly)
	class UPostProcessComponent* PostProcess;

private:
	//TakeDamage MemberVariable
	float DamageValue;
	class ACharacter* Attacker;
	class AActor* Causer;
};
