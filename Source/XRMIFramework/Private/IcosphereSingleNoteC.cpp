// Fill out your copyright notice in the Description page of Project Settings.


#include "IcosphereSingleNoteC.h"

#include "Utility.h"

AIcosphereSingleNoteC::AIcosphereSingleNoteC()
	: AActor() 
{
}

void AIcosphereSingleNoteC::SetMidiNoteNumber(int32 noteNumber)
{
	this->midiNoteNumber = noteNumber;
	this->noteName = Utility::getNoteFromMidiNumber(noteNumber);
}

// Called when the game starts or when spawned
void AIcosphereSingleNoteC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIcosphereSingleNoteC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

