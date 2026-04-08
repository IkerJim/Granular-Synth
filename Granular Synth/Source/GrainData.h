/*
  ==============================================================================

    GrainData.h
    Created: 8 Apr 2026 5:35:24pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Grain : public juce::ReferenceCountedObject
{
public:
    typedef juce::ReferenceCountedObjectPtr<Grain> Ptr;

    Grain(juce::AudioBuffer<float>* source);
    void synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

private:
    juce::AudioBuffer<float>* source;
    int length;
    int writePointer;
};