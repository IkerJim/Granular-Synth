/*
  ==============================================================================

    GrainScheduler.cpp
    Created: 8 Apr 2026 7:48:56pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainScheduler.h"

GrainScheduler::GrainScheduler() :
    nextOnset(0),
    grainPool(100)
{

}

GrainScheduler::~GrainScheduler()
{

}

void GrainScheduler::synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    jassert(source != nullptr);

    synthesizeActiveGrains(outputBuffer, startSample, numSamples);

    while (nextOnset < numSamples)
    {
        auto newGrain = grainPool.request(); // revisar

        newGrain->configurate(source, static_cast<int>(parameters.grainDuration * sourceSampleRate), static_cast<int>(parameters.grainSourcePosition * sourceLength)); // averiguar forma de enventanado

        //Grain::Ptr newGrain = new Grain(source, 
            //(int)(parameters.grainDuration * sourceSampleRate), 
            //(int)(parameters.grainSourcePosition * sourceLength));
        //grains.add(newGrain);
        newGrain->synthesize(outputBuffer, 
                             startSample + nextOnset, 
                             numSamples - nextOnset);

        nextOnset += (1 / parameters.grainDensity) * systemSampleRate;
    }

    nextOnset -= numSamples;
}

void GrainScheduler::reset()
{
    nextOnset = 0;
    source = nullptr;
    grainPool.clear();
}

void GrainScheduler::setSource(juce::AudioBuffer<float>* source, double sourceSampleRate, int sourceLength)
{
    jassert(source != nullptr);

    this->source = source;
    this->sourceSampleRate = sourceSampleRate;
    this->sourceLength = sourceLength;
}

void GrainScheduler::setParameters(const Parameters& newParameters, double systemSampleRate)
{
    parameters = newParameters;

    this->systemSampleRate = systemSampleRate;
}

void GrainScheduler::synthesizeActiveGrains(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    for (int i = 0; i < grainPool.get_size(); i++)
    {
        if (grainPool[i].get_is_used())
        {
            grainPool[i].get_var().synthesize(outputBuffer, startSample, numSamples);

            bool check = grainPool[i].get_var().checkBoundaries();
            if (!check)
            {
                grainPool.free(i);
            }
        }
    }
}