// Cerebral Paralysis... Think twice ;)

#pragma once

#include "CoreMinimal.h"
#include "EnemyFactoryData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EnemyFactorySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CEREBRALPARALYSIS_V2_API UEnemyFactorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	FEnemyFactoryData Data;

	bool DataLoaded;

public:
	void Construct(const FEnemyFactoryData NewData)
	{
		Data = NewData;
		DataLoaded = true;
	}

	UFUNCTION(BlueprintCallable)
	void SpawnZombieSoldier(UWorld* World, const FVector Position) const;
};
