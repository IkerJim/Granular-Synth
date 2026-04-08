/*
  ==============================================================================

    GrainSound.cpp
    Created: 7 Apr 2026 7:28:29pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainSound.h"

GrainSound::GrainSound(juce::AudioFormatReader& source):
    data(source.numChannels, source.lengthInSamples),
    length(source.lengthInSamples)
{
    source.read(&data, 0, length, 0, true, true);
}

bool 	GrainSound::appliesToNote(int midiNoteNumber)
{
    return true;
}

bool 	GrainSound::appliesToChannel(int midiChannel)
{
    return true;
}