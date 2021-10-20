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
	static FRotator MirrorRotatorAlongAxis(FRotator rotatorIn, FRotator axisRotator)
	{
		// Copy incoming axis rotator in order to change it
		auto modifiedAxisRotator = FRotator(axisRotator.Pitch, axisRotator.Yaw, axisRotator.Roll);
		// Don't take into account pitch (up-down head movement)
		modifiedAxisRotator.Pitch = 0;
		modifiedAxisRotator.Yaw = 0;
		modifiedAxisRotator.Roll = 0;
		// Convert axis rotator to quaternion & normalise
		auto mirroredNormalQuat = modifiedAxisRotator.Quaternion();
		mirroredNormalQuat.Normalize();
		// Return mirrored rotator
		return (mirroredNormalQuat * rotatorIn.Quaternion() * mirroredNormalQuat).Rotator();
	}
};
