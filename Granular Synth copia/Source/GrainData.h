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

    Grain();

    void configurate(juce::AudioBuffer<float>* sourceRef, int grainLength, int grainSamplePosition);

    Grain(juce::AudioBuffer<float>* source, int length, int sourcePos);
    void synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

    bool checkBoundaries() const;

private:
    juce::AudioBuffer<float>* source;
    int length;
    int samplePosition;
    int writePointer;

    std::vector<float> window;
};