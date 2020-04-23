/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================


SpectralDistortionAudioProcessorEditor::SpectralDistortionAudioProcessorEditor (SpectralDistortionAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), treeState(vts)

{
    //==================================================PARAMETERS======================================================
    // inputGain
    inputGainValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(treeState,
        "inputGain", inputGainDial);
    inputGainDial.setSliderStyle(Slider::Rotary);
    inputGainDial.setRange(-20.0f, 20.0f, 0.01f);
    inputGainDial.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 20);
    inputGainDial.setTextValueSuffix("dB");
    addAndMakeVisible(&inputGainDial);

    


    //Wet
    wetValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(treeState,
        "wet", wetDial);
    wetDial.setSliderStyle(Slider::Rotary);
    wetDial.setRange(0.0f, 1.0f, 0.01f);
    wetDial.setValue(0.5);
    wetDial.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 20);
    wetDial.setTextValueSuffix("%");
    addAndMakeVisible(&wetDial);
   
    // OutputGain
    outGainValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(treeState,
        "outGain", outGainDial);
    outGainDial.setSliderStyle(Slider::Rotary);
    outGainDial.setRange(-40.0f, 10.0f, 0.01f);
    outGainDial.setTextBoxStyle(Slider::TextBoxBelow, true, 40, 20);
    outGainDial.setTextValueSuffix("dB");
    addAndMakeVisible(&outGainDial);
    
    // Distortion Selection
    distortionSelectChoice = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(treeState,
        "distortionSelect", distortionSel);
    distortionSel.addItem("arcTan", 1);
    distortionSel.addItem("Hard Clip", 2);
    distortionSel.addItem("Soft Clip", 3);
    distortionSel.addItem("Soft Clip Exponential", 4);
    distortionSel.addItem("Full-Wave Rectifier", 5);
    distortionSel.addItem("Half-Wave Rectifier", 6);
    addAndMakeVisible(&distortionSel);


    // ==============================================FILTERS==============================================================
    
    
    filterCutoffValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(treeState,
        "filterCutoff", filterCutoffDial);
    filterCutoffDial.setSliderStyle(Slider::RotaryVerticalDrag);
    filterCutoffDial.setRange(0.0f, 20000.0f, 0.0f);
    filterCutoffDial.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 20);
    filterResonanceDial.setTextValueSuffix("Hz");
    addAndMakeVisible(&filterCutoffDial);

    filterResonanceValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(treeState,
        "filterResonance", filterResonanceDial);
    filterResonanceDial.setSliderStyle(Slider::RotaryVerticalDrag);
    filterResonanceDial.setRange(0.0f, 1.0f, 0.0f);
    filterResonanceDial.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 30);
    addAndMakeVisible(&filterResonanceDial);


    modeSelectChoice = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(treeState,
        "modeSelect", modeSel);
    modeSel.addItem("OFF", 1);
    modeSel.addItem("LPF12", 2);
    modeSel.addItem("LPF24", 3);
    modeSel.addItem("HPF12", 4);
    modeSel.addItem("HPF24", 5);  
    addAndMakeVisible(&modeSel);

    filterDriveValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(treeState,
        "filterDrive", filterDriveDial);
    filterDriveDial.setSliderStyle(Slider::RotaryVerticalDrag);
    filterDriveDial.setRange(0.0f, 1.0f, 0.0f);
    filterDriveDial.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 30);
    addAndMakeVisible(&filterDriveDial);

 //   addAndMakeVisible((inputGainKnob) = new Slider("Input Gain"));
  //  inputGainKnob->setSliderStyle(Slider::Rotary);
   // inputGainKnob ->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

   // addAndMakeVisible((rangeKnob) = new Slider("Range"));
    //rangeKnob->setSliderStyle(Slider::Rotary);
    //rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    //addAndMakeVisible((wetKnob) = new Slider("Wet/Dry"));
    //wetKnob->setSliderStyle(Slider::Rotary);
    //wetKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    //addAndMakeVisible((outGainKnob) = new Slider("Output Gain"));
    //outGainKnob->setSliderStyle(Slider::Rotary);
    //outGainKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    //addAndMakeVisible((DistortionType_) = new ComboBox("Distortion"));
    
    //inputGainAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "inputGain", *inputGainKnob);
    //rangeAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
    //wetAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "wet", *wetKnob);
    //outGainAttatchment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "outGain", *outGainKnob);
    //DistortionAttatchment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.getState(), "distortion", *DistortionType);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

setSize(700, 500);
   

}

SpectralDistortionAudioProcessorEditor::~SpectralDistortionAudioProcessorEditor()
{
}

//==============================================================================
void SpectralDistortionAudioProcessorEditor::paint(Graphics& g)
{

    g.fillAll(Colours::lightcoral);
    g.setColour(Colours::black);

    // Title Text
    g.setFont(30);
    g.drawFittedText("Distortion", 350, 0, 250, 10, Justification::centred, 1, 0.0f);
    // Parameter Labels 
    g.setFont(25);
    g.drawFittedText("Input Gain", ((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 1.8), 100, 100, Justification::centred, 1);
    g.drawFittedText("Wet", ((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 1.8), 100, 100, Justification::centred, 1);
    g.drawFittedText("Output Gain", ((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 1.8), 100, 100, Justification::centred, 1);
    g.drawFittedText("Tone", ((getWidth() / 5) * 1.5) - (100 / 2), (getHeight() / 2.88) - (100 / 2), 100, 100, Justification::centred, 1);
    g.drawFittedText("Resonance", ((getWidth() / 5) * 2.5) - (100 / 2), (getHeight() / 2.88) - (100 / 2), 100, 100, Justification::centred, 1);
    g.drawFittedText("Saturation", ((getWidth() / 5) * 3.5) - (100 / 2), (getHeight() / 2.88) - (100 / 2), 100, 100, Justification::centred, 1);


}

void SpectralDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    inputGainDial.setBounds(((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 1.8) - (100 / 2), 100, 100);
    wetDial.setBounds(((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 1.8) - (100 / 2), 100, 100);
    outGainDial.setBounds(((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 1.8) - (100 / 2), 100, 100);
    distortionSel.setBounds(((getWidth() / 5 * 4) - (100 / 2)), ((getHeight() / 1.8) - (100 / 2)), 100, 100);


    filterCutoffDial.setBounds(((getWidth() / 5) * 1.5) - (100 / 2), (getHeight()/5) - (100 / 2), 100, 100);
    filterResonanceDial.setBounds(((getWidth() / 5) * 2.5) - (100 / 2), (getHeight()/5) - (100 / 2), 100, 100);
    filterDriveDial.setBounds(((getWidth() / 5) * 3.5) - (100 / 2), (getHeight() / 5) - (100 / 2), 100, 100);
    modeSel.setBounds(((getWidth() / 5 * 4.5) - (100 / 2)), ((getHeight() / 5) - (100 / 2)), 100, 100);

   


}
