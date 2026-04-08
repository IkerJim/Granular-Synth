/*
  ==============================================================================

    GrainScheduler.h
    Created: 8 Apr 2026 5:32:52pm
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
    void synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
    void reset();

private:
    std::vector<Grain> grains;
    int nextOnset;
};