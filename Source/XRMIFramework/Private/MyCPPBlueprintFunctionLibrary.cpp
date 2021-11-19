// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCPPBlueprintFunctionLibrary.h"

TArray<int> UMyCPPBlueprintFunctionLibrary::singleNoteMap = {0};
TArray<int> UMyCPPBlueprintFunctionLibrary::majMap = {0, 4, 7};
TArray<int> UMyCPPBlueprintFunctionLibrary::minMap = {0, 3, 7};
TArray<int> UMyCPPBlueprintFunctionLibrary::dimMap = {0, 4, 6};
TArray<int> UMyCPPBlueprintFunctionLibrary::augMap = {0, 4, 8};
TArray<int> UMyCPPBlueprintFunctionLibrary::domMap = {0, 4, 7, 10};
TArray<int> UMyCPPBlueprintFunctionLibrary::maj7Map = {0, 4, 7, 11};
TArray<int> UMyCPPBlueprintFunctionLibrary::min7Map = {0, 3, 7, 10};
TArray<int> UMyCPPBlueprintFunctionLibrary::d7Map = {0, 3, 6, 9};
TArray<int> UMyCPPBlueprintFunctionLibrary::hd7Map = {0, 3, 6, 10};
TArray<int> UMyCPPBlueprintFunctionLibrary::sus2Map = {0, 2, 7};
TArray<int> UMyCPPBlueprintFunctionLibrary::sus4Map = {0, 5, 7};

FString UMyCPPBlueprintFunctionLibrary::GetNoteNameFromNumber(int number)
{
	return Utility::getNoteFromMidiNumber(number);
}
