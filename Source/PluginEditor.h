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
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SpectralDistortionAudioProcessor& processor;
    AudioProcessorValueTreeState& treeState;

    Slider cutoffDial;
    Slider resonanceDial;
    Slider driveDial;
    ComboBox modeSel;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> cutoffValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> resonanceValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> driveValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> modeChoice;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralDistortionAudioProcessorEditor)
};
