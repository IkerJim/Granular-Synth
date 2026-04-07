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
    bool 	appliesToNote(int midiNoteNumber) override;
    bool 	appliesToChannel(int midiChannel) override;

private:
};