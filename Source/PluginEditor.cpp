/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SignalNotesAudioProcessorEditor::SignalNotesAudioProcessorEditor (SignalNotesAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible (noteEditor);

    noteEditor.setMultiLine (true);
    noteEditor.setReturnKeyStartsNewLine (true);
    noteEditor.setScrollbarsShown (true);
    
    noteEditor.setText (audioProcessor.getNoteText(), juce::dontSendNotification);

    noteEditor.onTextChange = [this]
    {
        audioProcessor.setNoteText (noteEditor.getText());
    };

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

SignalNotesAudioProcessorEditor::~SignalNotesAudioProcessorEditor()
{
}

//==============================================================================
void SignalNotesAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // g.setColour (juce::Colours::white);
    // g.setFont (juce::FontOptions (15.0f));
    // g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SignalNotesAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // setBounds (x, y, width, height)
    noteEditor.setBounds (10, 10, 380, 280);
}
