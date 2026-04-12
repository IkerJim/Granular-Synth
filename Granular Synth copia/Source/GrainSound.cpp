/*
  ==============================================================================

    GrainSound.cpp
    Created: 8 Apr 2026 7:48:12pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainSound.h"

GrainSound::GrainSound(juce::AudioFormatReader& source) :
    data(source.numChannels, source.lengthInSamples),
    sampleRate(source.sampleRate),
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

void GrainSound::setParameters(const GrainScheduler::Parameters& newParameters)
{
    parameters = newParameters;
}