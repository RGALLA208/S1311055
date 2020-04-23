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

    Label inputGainLabel;

    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inputGainValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> wetValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> outGainValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> distortionSelectChoice;


    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> filterResonanceValue;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> filterDriveValue;
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> modeSelectChoice;
//    ScopedPointer<Slider> inputGainKnob;
  //  ScopedPointer<Slider> rangeKnob;
    //ScopedPointer<Slider> wetKnob;
    //ScopedPointer<Slider> outGainKnob;
   // ScopedPointer<ComboBox> DistortionType;
    
   // ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> inputGainAttatchment;
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttatchment;
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> wetAttatchment;
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> outGainAttatchment;
   // ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> DistortionAttatchment;
    

   

  



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralDistortionAudioProcessorEditor)
};
