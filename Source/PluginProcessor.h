/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class SpectralDistortionAudioProcessor  : public AudioProcessor, public AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    SpectralDistortionAudioProcessor();
    ~SpectralDistortionAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

   
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

   
    void parameterChanged(const String& parameterID, float newValue) override;
    AudioProcessorValueTreeState treeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

public:
    
    AudioParameterFloat* prmPreLP, * prmPostHP;
   
   


private:
    dsp::LadderFilter<float> ladderFilter;
    dsp::Oversampling<float> Oversample;
   
 

    using Filter = dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>>;
    Filter preLowPassFilter, postHighPassFilter;

    //==============================================================================


  
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectralDistortionAudioProcessor)
};
