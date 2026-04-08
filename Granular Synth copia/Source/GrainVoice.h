/*
  ==============================================================================

    GrainVoice.h
    Created: 8 Apr 2026 7:48:30pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GrainSound.h"
#include "GrainScheduler.h"

class GrainVoice : public juce::SynthesiserVoice
{
public:
    bool 	canPlaySound(juce::SynthesiserSound* s) override;
    void 	startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void 	stopNote(float velocity, bool allowTailOff) override;
    void 	pitchWheelMoved(int newPitchWheelValue) override;
    void 	controllerMoved(int controllerNumber, int newControllerValue) override;
    void 	renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    GrainScheduler scheduler;
};