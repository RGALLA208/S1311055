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
    SpectralDistortionAudioProcessorEditor (SpectralDistortionAudioProcessor&);
    ~SpectralDistortionAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SpectralDistortionAudioProcessor& processor;
   
    ScopedPointer<Slider> driveKnob;
    ScopedPointer<Slider> rangeKnob;
    ScopedPointer<Slider> wetKnob;
    ScopedPointer<Slider> volumeKnob;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttatchment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttatchment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> wetAttatchment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttatchment;
    

    Slider inGainDial;
    Slider driveDial;
    ComboBox distortionSel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralDistortionAudioProcessorEditor)
};
