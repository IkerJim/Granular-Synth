/*
  ==============================================================================

    GrainData.cpp
    Created: 8 Apr 2026 7:49:16pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainData.h"

Grain::Grain(juce::AudioBuffer<float>* source, int length, int sourcePos) :
    writePointer(0),
    source(source),
    length(length),
    sourcePos(sourcePos)
{
    jassert(source != nullptr);
    jassert(sourcePos <= source->getNumSamples());
}

void Grain::synthesize(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    int limit = std::min(length - writePointer, numSamples);

    float* outL = outputBuffer.getWritePointer(0, startSample);
    float* outR = outputBuffer.getNumChannels() > 1 ? outputBuffer.getWritePointer(1, startSample) : nullptr;

    const float* inL = source->getReadPointer(0, sourcePos + writePointer);
    const float* inR = source->getNumChannels() > 1 ? source->getReadPointer(1, sourcePos + writePointer) : inL;

    if (outR != nullptr)
    {
        juce::FloatVectorOperations::add(outL, inL, limit);
        juce::FloatVectorOperations::add(outR, inR, limit);
    }
    else
    {
        juce::FloatVectorOperations::addWithMultiply(outL, inL, 0.5, limit);
        juce::FloatVectorOperations::addWithMultiply(outL, inR, 0.5, limit);
    }

    writePointer += limit;
}