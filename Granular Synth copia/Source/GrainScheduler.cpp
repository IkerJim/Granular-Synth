/*
  ==============================================================================

    GrainScheduler.cpp
    Created: 8 Apr 2026 7:48:56pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainScheduler.h"

GrainScheduler::GrainScheduler() :
    nextOnset(0)
{

}

GrainScheduler::~GrainScheduler()
{

}

void GrainScheduler::synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    DBG(nextOnset);

    jassert(source != nullptr);

    synthesizeActiveGrains(outputBuffer, startSample, numSamples);

    while (nextOnset < numSamples)
    {
        Grain::Ptr newGrain = new Grain(source);
        grains.add(newGrain);
        newGrain->synthesize(outputBuffer, startSample + nextOnset, numSamples - nextOnset);

        nextOnset += 5000;
    }

    nextOnset -= numSamples;
}

void GrainScheduler::reset()
{
    nextOnset = 0;
    source = nullptr;
    grains.clear();
}

void GrainScheduler::setSource(juce::AudioBuffer<float>* source)
{
    jassert(source != nullptr);

    this->source = source;
}

void GrainScheduler::synthesizeActiveGrains(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    for (auto grain : grains)
    {
        grain->synthesize(outputBuffer, startSample, numSamples);
    }
}