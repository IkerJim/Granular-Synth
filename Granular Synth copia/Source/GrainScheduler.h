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

template <typename T>
class pool
{
public:
    struct Telement
    {
        Telement() :
            is_used(false),
            var()
        {

        }

        void reset()
        {
            is_used = false;
            var.reset();
        }

        void set_is_used(bool state)
        {
            if (state != is_used)
                is_used = state;
        }

        bool get_is_used() const
        {
            return is_used;
        }

        T& get_var()
        {
            return var;
        }

    private:
        bool is_used;
        T var;
    };

    pool (int num)
    {
        container.reserve(300);
        container.resize(num);
        size = num;
    }

    T* request()
    {
        for (auto& element : container)
            if (element.get_is_used() == false)
            {
                element.set_is_used(true);
                return &element.get_var();
            }

        return nullptr;
    }

    Telement& operator[] (int index)
    {
        return container[index];
    }

    int get_size() const
    {
        return size;
    }

    void free(int index)
    {
        if (container[index].get_is_used())
            container[index].set_is_used(false);
    }

    void clear()
    {
        for (int i = 0; i < get_size(); i++)
        {
            free(i);
        }
    }

private:
    std::vector<Telement> container;
    int size;
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