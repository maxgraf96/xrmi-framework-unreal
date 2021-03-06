// Fill out your copyright notice in the Description page of Project Settings.


#include "IMLHelper.h"

#include "InteractML.h"

// Sets default values
AIMLHelper::AIMLHelper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIMLHelper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIMLHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIMLHelper::InitialiseDataset(UInteractMLTrainingSet* TrainingSet)
{
	auto cache = TrainingSet->GetLabelCache();

	const class UInteractMLLabel* LabelType = cache.LabelType;

	TArray<FInteractMLLabelCapture> Labels = cache.Labels;

	TArray<FInteractMLStringMapping> StringsMap = cache.StringsMap;

	UE_LOG(LogActor, Warning, TEXT("%i"), TrainingSet->GetLabelCount())

	int a = 2;
}

