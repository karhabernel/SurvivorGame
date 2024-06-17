#include "Characters/CEnemy_Master.h"

#include "Global.h"
#include "Cplayer.h"
#include "Components/StatComponent.h"

ACEnemy_Master::ACEnemy_Master()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACEnemy_Master::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACEnemy_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACEnemy_Master::BeHitted(float InDamage, AActor* DamageCauser)
{
	//Add Force
	FVector start = GetActorLocation();
	FVector target = DamageCauser->GetActorLocation();
	FVector direction = (start - target).GetSafeNormal();
	float DefaultLaunchValue = 25.f;
	FVector force = direction * InDamage * DefaultLaunchValue;

	ACPlayer* player = Cast<ACPlayer>(DamageCauser);
	if (!!player)
	{
		force = direction * InDamage * player->GetStatComponent()->GetLaunchValue();
		GetMesh()->AddForceAtLocation(force, start);
	}
	else
	{
		GetMesh()->AddForceAtLocation(force, start);
	}

}

