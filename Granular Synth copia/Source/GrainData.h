/*
  ==============================================================================

    GrainData.h
    Created: 8 Apr 2026 7:49:16pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Grain : public juce::ReferenceCountedObject
{
public:
    typedef juce::ReferenceCountedObjectPtr<Grain> Ptr;

    Grain(juce::AudioBuffer<float>* source, int length, int sourcePos);
    void synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

private:
    juce::AudioBuffer<float>* source;
    int length;
    int sourcePos;
    int writePointer;
};