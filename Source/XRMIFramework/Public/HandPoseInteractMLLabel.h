// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractMLLabel.h"
#include "HandPoseInteractMLLabel.generated.h"

/**
 * 
 */
UCLASS()
class XRMIFRAMEWORK_API UHandPoseInteractMLLabel : public UInteractMLLabel
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 HandPoseID;
	
};
