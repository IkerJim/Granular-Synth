/*
  ==============================================================================

    GrainSound.h
    Created: 8 Apr 2026 7:48:12pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GrainScheduler.h"

class GrainSound : public juce::SynthesiserSound
{
public:
    GrainSound(juce::AudioFormatReader& source);
    bool 	appliesToNote(int midiNoteNumber) override;
    bool 	appliesToChannel(int midiChannel) override;
    void setParameters(const GrainScheduler::Parameters& newParameters);

private:
    friend class GrainVoice;

    juce::AudioBuffer<float> data;
    double sampleRate;
    int length;

    GrainScheduler::Parameters parameters;
};