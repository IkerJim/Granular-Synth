/*
  ==============================================================================

    GrainVoice.h
    Created: 7 Apr 2026 7:28:43pm
    Author:  ikerr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GrainSound.h"

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
    juce::AudioBuffer<float>* source;
};