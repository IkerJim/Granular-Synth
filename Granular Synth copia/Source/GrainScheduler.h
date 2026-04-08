/*
  ==============================================================================

    GrainScheduler.h
    Created: 8 Apr 2026 7:48:56pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GrainData.h"

class GrainScheduler
{
public:
    GrainScheduler();
    ~GrainScheduler();
    void synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
    void reset();
    void setSource(juce::AudioBuffer<float>* source);

private:
    juce::ReferenceCountedArray<Grain> grains;
    int nextOnset;
    juce::AudioBuffer<float>* source;

    void synthesizeActiveGrains(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
};