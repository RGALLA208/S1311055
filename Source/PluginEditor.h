/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SpectralDistortionAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SpectralDistortionAudioProcessorEditor (SpectralDistortionAudioProcessor&, AudioProcessorValueTreeState&);
    ~SpectralDistortionAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
  

    SpectralDistortionAudioProcessor& processor;
    AudioProcessorValueTreeState& treeState;

    //Controls
    Slider inputGainDial;
    Slider wetDial;
    Slider outGainDial;
    ComboBox distortionSel;

    //Filter
    Slider filterCutoffDial;
    Slider filterResonanceDial;
    Slider filterDriveDial;
    ComboBox modeSel;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inputGainValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> wetValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> outGainValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> distortionSelectChoice;


    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> filterResonanceValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> filterDriveValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> modeSelectChoice;

   


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralDistortionAudioProcessorEditor)
};
