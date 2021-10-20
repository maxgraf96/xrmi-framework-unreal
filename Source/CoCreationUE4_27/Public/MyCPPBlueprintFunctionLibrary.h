// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	static FRotator MirrorRotatorAlongZAxis(FRotator rotatorIn)
	{
		auto mirroredNormalQuat = FQuat(0, 0, 1, 0);
		return (mirroredNormalQuat * rotatorIn.Quaternion() * mirroredNormalQuat).Rotator();
	}
};
