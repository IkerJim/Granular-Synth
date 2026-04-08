/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GranularSynthcopiaAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GranularSynthcopiaAudioProcessorEditor (GranularSynthcopiaAudioProcessor&);
    ~GranularSynthcopiaAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GranularSynthcopiaAudioProcessor& audioProcessor;

    juce::TextButton openButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GranularSynthcopiaAudioProcessorEditor)
};
