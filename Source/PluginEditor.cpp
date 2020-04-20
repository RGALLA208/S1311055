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

    addAndMakeVisible((inputGainKnob) = new Slider("Input Gain"));
    inputGainKnob->setSliderStyle(Slider::Rotary);
    inputGainKnob ->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible((rangeKnob) = new Slider("Range"));
    rangeKnob->setSliderStyle(Slider::Rotary);
    rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible((wetKnob) = new Slider("Wet/Dry"));
    wetKnob->setSliderStyle(Slider::Rotary);
    wetKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible((outGainKnob) = new Slider("Output Gain"));
    outGainKnob->setSliderStyle(Slider::Rotary);
    outGainKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    //addAndMakeVisible((DistortionType_) = new ComboBox("Distortion"));
    
    inputGainAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "inputGain", *inputGainKnob);
    rangeAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
    wetAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "wet", *wetKnob);
    outGainAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "outGain", *outGainKnob);
    //DistortionAttatchment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.getState(), "distortion", *DistortionType);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

setSize(1000, 1000);
   

}

SpectralDistortionAudioProcessorEditor::~SpectralDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SpectralDistortionAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
    g.setColour(Colours::white);
    g.setFont(15.0f);
 
    g.drawFittedText("Input Gain", ((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 2), 100, 100, Justification::centred, 1);
    g.drawFittedText("Range", ((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 2), 100, 100, Justification::centred, 1);
    g.drawFittedText("Wet", ((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 2), 100, 100, Justification::centred, 1);
    g.drawFittedText("Output Gain", ((getWidth() / 5 ) * 4) - (100 / 2), (getHeight() / 2), 100, 100, Justification::centred, 1);

   // g.drawText("Distortion  Type", ((getWidth() / 5 * 4) - (100 / 2)), ((getHeight() / 2)), 100, 100, Justification::centred, `);

}

void SpectralDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    inputGainKnob->setBounds(((getWidth() / 5) * 1) - (100 / 2),(getHeight() / 2) - (100 / 2), 100, 100);
    rangeKnob->setBounds(((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    wetKnob->setBounds(((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
    outGainKnob->setBounds(((getWidth() / 5) * 4) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	//DistortionType-> setBounds(((getWidth() / 5 * 5) - (100 / 2)), ((getHeight() / 2) - (100 / 2)), 100, 100);
   


}
