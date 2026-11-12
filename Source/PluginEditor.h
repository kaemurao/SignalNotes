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
class SignalNotesAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    SignalNotesAudioProcessorEditor (SignalNotesAudioProcessor&);
    ~SignalNotesAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SignalNotesAudioProcessor& audioProcessor;

    juce::LookAndFeel_V4 signalNotesLookAndFeel;
    juce::TextEditor noteEditor;
    juce::TextButton fontSizeButton { "A" };
    juce::ComboBox fontSizeSelector;

    bool isFontSizeSelectorOpen = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SignalNotesAudioProcessorEditor)
};
