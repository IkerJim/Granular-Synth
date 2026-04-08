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

void 	GrainVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* s, int currentPitchWheelPosition)
{
    if (auto sound = dynamic_cast<GrainSound*>(s))
    {
        source = &sound->data;
    }
}

void 	GrainVoice::stopNote(float velocity, bool allowTailOff)
{
    clearCurrentNote();

    source = nullptr;
    scheduler.reset();
}

void 	GrainVoice::pitchWheelMoved(int newPitchWheelValue)
{

}

void 	GrainVoice::controllerMoved(int controllerNumber, int newControllerValue)
{

}

void 	GrainVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    if (auto playingSound = dynamic_cast<GrainSound*>(getCurrentlyPlayingSound().get()))
    {
        scheduler.synthesize(outputBuffer, startSample, numSamples);
    }
}