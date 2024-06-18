#include "Weapons/Weapon_Overlapped_Master.h"
#include "GameFramework/Character.h"
#include "Engine/DamageEvents.h"

#include "Global.h"

AWeapon_Overlapped_Master::AWeapon_Overlapped_Master()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AWeapon_Overlapped_Master::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon_Overlapped_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon_Overlapped_Master::OnAttachmentBeginOverlap(UPrimitiveComponent* InOverlappedComponent, ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
	int32 prevHittedCharactersNum = HittedCharacters.Num();
	HittedCharacters.AddUnique(InOtherCharacter);

	// 맞은 객체가 이미 맞았던 적인지 확인 (AddUnique로 늘었는지 확인)
	CheckFalse(prevHittedCharactersNum < HittedCharacters.Num());

	//todo. Power와 effect 어디서 가져올 것인지? 데이터 구성 필요
	//Take Damage
	FDamageEvent damageEvent;
	InOtherCharacter->TakeDamage(Power, damageEvent, InAttacker->GetController(), InCauser);

	//Spawn Particle
	UParticleSystem* effect = ;
	if (!!effect)
	{
		FTransform trasnform = GetActorTransform();
		trasnform.AddToTranslation(InOverlappedComponent->GetComponentLocation());
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), effect, trasnform);
	}
}

void AWeapon_Overlapped_Master::OnAttachmentEndOverlap(UPrimitiveComponent* InOverlappedComponent, ACharacter* InAttacker, AActor* InCauser, ACharacter* InOtherCharacter)
{
}

