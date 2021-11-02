// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <cmath>
#include <memory>

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MyCPPBlueprintFunctionLibrary.generated.h"

using namespace std;


/**
 * 
 */
UCLASS()
class COCREATIONUE4_27_API UMyCPPBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	static FQuat GetQuatFromRotator(FRotator rotator)
	{
		return rotator.Quaternion();
	}
	
	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	static float GetFractionFromFloat(float InValue, float OutIntPart)
    {
        return modf(InValue, &OutIntPart);
    }
};
