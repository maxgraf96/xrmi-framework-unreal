// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/UxtHandInteractionActor.h"
#include "IcosphereSingleNoteC.generated.h"

/**
 * 
 */
UCLASS()
class XRMIFRAMEWORK_API AIcosphereSingleNoteC : public AActor
{
	GENERATED_BODY()
public:
	AIcosphereSingleNoteC();
    
    // Sets midi note number and name
    UFUNCTION(BlueprintCallable, Category="Note")
    void SetMidiNoteNumber(int32 noteNumber);
    
    // My properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Note")
    FString noteName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Note")
    int32 midiNoteNumber;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
