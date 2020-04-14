/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpectralDistortionAudioProcessorEditor::SpectralDistortionAudioProcessorEditor (SpectralDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.


	setSize (400, 300);
}

SpectralDistortionAudioProcessorEditor::~SpectralDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SpectralDistortionAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colour(0xff323e44));

   
   
}

void SpectralDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
}
