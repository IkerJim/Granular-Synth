/*
  ==============================================================================

    GrainVoice.cpp
    Created: 7 Apr 2026 7:28:43pm
    Author:  ikerr

  ==============================================================================
*/

#include "GrainVoice.h"

bool 	GrainVoice::canPlaySound(juce::SynthesiserSound* s)
{
    return dynamic_cast<GrainSound*>(s) != nullptr;
}

void 	GrainVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{

}

void 	GrainVoice::stopNote(float velocity, bool allowTailOff)
{

}

void 	GrainVoice::pitchWheelMoved(int newPitchWheelValue)
{

}

void 	GrainVoice::controllerMoved(int controllerNumber, int newControllerValue)
{

}

void 	GrainVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{

}