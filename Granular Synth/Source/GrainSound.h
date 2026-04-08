/*
  ==============================================================================

    GrainSound.h
    Created: 7 Apr 2026 7:28:29pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class GrainSound : public juce::SynthesiserSound
{
public:
    GrainSound(juce::AudioFormatReader& source);
    bool 	appliesToNote(int midiNoteNumber) override;
    bool 	appliesToChannel(int midiChannel) override;

private:
    friend class GrainVoice;

    juce::AudioBuffer<float> data;
    int length;
};