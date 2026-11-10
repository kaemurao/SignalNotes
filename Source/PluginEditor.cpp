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
    noteEditor.setLookAndFeel (&signalNotesLookAndFeel);

    noteEditor.setMultiLine (true);
    noteEditor.setReturnKeyStartsNewLine (true);
    noteEditor.setScrollbarsShown (true);

    // background
    noteEditor.setColour (
        juce::TextEditor::backgroundColourId,
        juce::Colour::fromRGB (37, 37, 37)
    );

    // text
    noteEditor.setColour (
        juce::TextEditor::textColourId,
        juce::Colour::fromRGB (229, 229, 229)
    );

    // cursor
    noteEditor.setColour (
        juce::CaretComponent::caretColourId,
        juce::Colour::fromRGB (255, 181, 6)
    );

    // remove editor outline
    noteEditor.setColour (
        juce::TextEditor::outlineColourId,
        juce::Colours::transparentBlack
    );

    noteEditor.setColour (
        juce::TextEditor::focusedOutlineColourId,
        juce::Colours::transparentBlack
    );

    // scrollbar colours
    signalNotesLookAndFeel.setColour (
        juce::ScrollBar::backgroundColourId,
        juce::Colour::fromRGB (45, 45, 45)
    );

    signalNotesLookAndFeel.setColour (
        juce::ScrollBar::thumbColourId,
        juce::Colour::fromRGB (55, 55, 55)
    );

    // signalNotesLookAndFeel.setColour (
    //     juce::ScrollBar::trackColourId,
    //     juce::Colour::fromRGB (48, 48, 48)
    // );
    
    noteEditor.setText (audioProcessor.getNoteText(), juce::dontSendNotification);

    noteEditor.onTextChange = [this]
    {
        audioProcessor.setNoteText (noteEditor.getText());
    };

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque (true);
    setSize (400, 300);
    setResizable (true, true);
    setResizeLimits (320, 240, 10000, 10000);
}

SignalNotesAudioProcessorEditor::~SignalNotesAudioProcessorEditor()
{
}

//==============================================================================
void SignalNotesAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll (juce::Colour::fromRGB (37, 37, 37));

    // g.setColour (juce::Colours::white);
    // g.setFont (juce::FontOptions (15.0f));
    // g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SignalNotesAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // setBounds (x, y, width, height)
    // noteEditor.setBounds (10, 10, 380, 280); // default
    noteEditor.setBounds (10, 10, getWidth() - 20, getHeight() - 20);
}
