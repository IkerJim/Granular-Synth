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

template <typename Type>
class pool
{
public:
    pool (int num)
    {
        v.resize(num);
    }

    Type* request()
    {
        for (auto& element : v)
        {
            if (element.is_used == false)
            {
                element.is_used = true;
                return &element.var;
            }
        }
    }

private:
    struct TypeElement
    {
        TypeElement ():
            is_used (false),
            var()
        {

        }

        void reset()
        {
            is_used = false;
            var.reset();
        }

        bool is_used;
        Type var;
    };

    std::vector<TypeElement> v;
};

class GrainScheduler
{
public:
    GrainScheduler();
    ~GrainScheduler();
    void synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
    void reset();
    void setSource(juce::AudioBuffer<float>* source, double sourceSampleRate, int sourceLength);

    struct Parameters
    {
        Parameters() = default;
        Parameters(float grainDensity,
                   float grainDuration,
                   float grainSourcePosition):
            grainDensity(grainDensity),
            grainDuration(grainDuration),
            grainSourcePosition(grainSourcePosition)
        {

        }

        float grainDensity = 5.0f, grainDuration = 0.1f, grainSourcePosition = 0.0f;
    };

    void setParameters(const Parameters& newParameters, double systemSampleRate);

private:
    juce::ReferenceCountedArray<Grain> grains;
    int nextOnset;

    juce::AudioBuffer<float>* source;
    double sourceSampleRate;
    int sourceLength;

    Parameters parameters;
    double systemSampleRate;

    pool<Grain> grainPool;

    void synthesizeActiveGrains(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
};