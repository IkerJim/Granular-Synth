/*
  ==============================================================================

    GrainScheduler.cpp
    Created: 8 Apr 2026 5:32:52pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainScheduler.h"

GrainScheduler::GrainScheduler():
    nextOnset(0)
{

}

void GrainScheduler::synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    DBG(nextOnset);

    while (nextOnset < numSamples)
    {
        nextOnset += 5000;
    }

    nextOnset -= numSamples;
}

void GrainScheduler::reset()
{
    nextOnset = 0;
}