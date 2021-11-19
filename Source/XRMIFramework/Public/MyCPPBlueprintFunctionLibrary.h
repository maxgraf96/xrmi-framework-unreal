// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <cmath>
#include <memory>

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Utility.h"

#include "MyCPPBlueprintFunctionLibrary.generated.h"


using namespace std;

UENUM(BlueprintType)
enum class EChord : uint8 {
	singleNote			UMETA(DisplayName="single note"),
	maj					UMETA(DisplayName="major"),
	min					UMETA(DisplayName="minor"),
	dim					UMETA(DisplayName="diminished"),
	aug					UMETA(DisplayName="augmented"),
	dom					UMETA(DisplayName="dominant"),
	maj7				UMETA(DisplayName="major 7th"),
	min7				UMETA(DisplayName="minor 7th"),
	d7					UMETA(DisplayName="diminished 7th"),
	hd7					UMETA(DisplayName="half-diminished 7th"),
};

/**
 * 
 */
UCLASS()
class XRMIFRAMEWORK_API UMyCPPBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
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

	/* Chord maps (defined in cpp file) */
	static TArray<int> singleNoteMap;
	static TArray<int> majMap;
	static TArray<int> minMap;
	static TArray<int> dimMap;
	static TArray<int> augMap;
	static TArray<int> domMap;
	static TArray<int> maj7Map;
	static TArray<int> min7Map;
	static TArray<int> d7Map;
	static TArray<int> hd7Map;
	static TArray<int> sus2Map;
	static TArray<int> sus4Map;
	
    
    UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
    static TArray<int> GetChordMap(EChord chord)
	{
		switch(chord)
		{
		case EChord::singleNote:
			return singleNoteMap;
		case EChord::maj:
			return majMap;
		case EChord::min:
			return minMap;
		case EChord::dim:
			return dimMap;
		case EChord::aug:
			return augMap;
		case EChord::dom:
			return domMap;
		case EChord::maj7:
			return maj7Map;
		case EChord::min7:
			return min7Map;
		case EChord::d7:
			return d7Map;
		case EChord::hd7:
			return hd7Map;
		default:
			return singleNoteMap;
		}
	}

	UFUNCTION(BlueprintCallable, Category = "MyCPPLibrary")
	static FString GetNoteNameFromNumber(int number);

};

