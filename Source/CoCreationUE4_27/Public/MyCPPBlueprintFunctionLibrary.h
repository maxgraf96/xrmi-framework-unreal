// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InteractML/Public/InteractMLParameters.h"

#include "MyCPPBlueprintFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class COCREATIONUE4_27_API UMyCPPBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	FInteractMLParameters* params;
	
	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	static FInteractMLParameters CreateParameters(float myFloat)
	{
		TSharedPtr<struct FInteractMLParameterCollection> ptr (new FInteractMLParameterCollection);

		auto test = FInteractMLParameters(ptr);
		test.Ptr->Reset();
		test.Ptr->Add(myFloat);

		
		
		return test;
	}
};
