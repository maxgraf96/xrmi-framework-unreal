// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <string>
#include <vector>

/**
 * 
 */
class COCREATIONUE4_27_API Utility
{
public:
	Utility();
	
	static FString getNoteFromMidiNumber(int midiNote)
	{
		const std::vector<std::string> noteNames = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
		const int32 octave = (midiNote / 12) - 1;
		FString test = FString(noteNames[midiNote % 12].c_str()) + FString::FromInt(octave);
		return test;
		return FString("Wee");
	}
	
	~Utility();
};
