// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InteractML/Public/InteractMLParameters.h"

#include "IMLHelper.generated.h"

UCLASS()
class COCREATIONUE4_27_API AIMLHelper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIMLHelper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	FInteractMLParameters CreateParameters(TArray<float> floats)
	{
		const TSharedPtr<struct FInteractMLParameterCollection> ptr = TSharedPtr<struct FInteractMLParameterCollection>(new FInteractMLParameterCollection);
		// Clear any old data from parameter collection
		ptr->Clear();
		
		// Create new wrapper
		auto params = FInteractMLParameters(ptr);

		// Add data
		for (const auto floatIn : floats) 
			params.Ptr->Add(floatIn);
		
		return params;
	}

	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	FInteractMLParameters CreateParametersFromQuats(TArray<FQuat> quats)
	{
		const TSharedPtr<struct FInteractMLParameterCollection> ptr = TSharedPtr<struct FInteractMLParameterCollection>(new FInteractMLParameterCollection);
		// Clear any old data from parameter collection
		ptr->Clear();
		
		// Create new wrapper
		auto params = FInteractMLParameters(ptr);

		// Add data
		for (const auto quatIn : quats) 
			params.Ptr->Add(quatIn);
		
		return params;
	}

	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	FInteractMLParameters CreateParametersFromRotatorArray(TArray<FRotator> rotators)
	{
		const TSharedPtr<struct FInteractMLParameterCollection> ptr = TSharedPtr<struct FInteractMLParameterCollection>(new FInteractMLParameterCollection);
		// Clear any old data from parameter collection
		ptr->Clear();
		
		// Create new wrapper
		auto params = FInteractMLParameters(ptr);

		// Add data
		for (const auto rotatorIn : rotators) 
			params.Ptr->Add(rotatorIn.Vector());
		
		return params;
	}

};
