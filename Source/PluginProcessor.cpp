/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpectralDistortionAudioProcessor::SpectralDistortionAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	), treeState(*this, nullptr, Identifier("PARAMETERS"),
{
	std::make_unique<AudioParameterFloat>("inputGain", "Input Gain", -60.0f, 40.0f, 0.01f),
		std::make_unique<AudioParameterFloat>("wet", "Wet", 0.0f, 1.0f, 0.001f),
		std::make_unique<AudioParameterFloat>("outGain", "Output Gain", -60.0f, 30.0f, 0.01f),
		std::make_unique<AudioParameterChoice>("distortionSelect", "Distortion Type", StringArray("aTan", "Hard Clip",
			"Soft Clip", "Soft Clip Exponential", "Full-Wave Rectifier", "Half-Wave Rectifier"), 0),
		std::make_unique<AudioParameterFloat>("filterCutoff", "Filter Cutoff", 20.0f, 20000.0f, 20000.0f),
		std::make_unique<AudioParameterFloat>("filterResonance", "Filter Resonance", 0.0f, 1.10f, 0.15f)
})






#endif 
{
	const StringArray params = { "inputGain", "wet", "outGain", "distortionSelect", "filterCutoff","filterResonance" };
	for (int i = 0; i <= 3; ++i)
	{
		// adds a listener to each parameter in the array.
		treeState.addParameterListener(params[i], this);
	}


}



SpectralDistortionAudioProcessor::~SpectralDistortionAudioProcessor()
{
}



//==============================================================================
const String SpectralDistortionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SpectralDistortionAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SpectralDistortionAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SpectralDistortionAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SpectralDistortionAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SpectralDistortionAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SpectralDistortionAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SpectralDistortionAudioProcessor::setCurrentProgram (int index)
{
}

const String SpectralDistortionAudioProcessor::getProgramName (int index)
{
    return {};
}

void SpectralDistortionAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SpectralDistortionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	dsp::ProcessSpec spec;
	spec.sampleRate = sampleRate;
	spec.maximumBlockSize = samplesPerBlock;
	spec.numChannels = getTotalNumOutputChannels();
	ladderFilter.reset();
	ladderFilter.prepare(spec);
	ladderFilter.setEnabled(true);



}

void SpectralDistortionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpectralDistortionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif


void SpectralDistortionAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{

	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	juce::dsp::AudioBlock<float> block(buffer);

	auto processingContext = dsp::ProcessContextReplacing<float>(block);
	ladderFilter.process(processingContext);
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.

	
	

	float inputGaindB = *treeState.getRawParameterValue("inputGain"); //Linear Value
	float wet = *treeState.getRawParameterValue("wet");
	float outGaindB = *treeState.getRawParameterValue("outGain");
	int distortionSelect = *treeState.getRawParameterValue("distortionSelect");
	float LPcutoff = *treeState.getRawParameterValue("filterCutoff");
	float LPresonance = *treeState.getRawParameterValue("filterResonance");

	float inputGain = Decibels::decibelsToGain(inputGaindB);
	float  outGain = Decibels::decibelsToGain(outGaindB);
	
	
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
		
		
		// ..do something to the data...
			for (int i = 0; i < buffer.getNumSamples(); ++i) {

			channelData[i] *=  inputGain; //Apply input Gain

				float in = channelData[i];
				
				auto cleanSignal = in;

				float out;


		if (distortionSelect == 1) { // aTan Function
			if (in > 0) {
		
				out = (1 / tanh(in)) * tanh(in);
			}
			else 
				out = -(1 / tanh(in)) * (0.5*tanh(in));
		}

	

		if (distortionSelect == 2) { // Hard Clipping
			float threshold = 1.0f; // Thresh1 = 1.0
			
			if (in > threshold)
				out = ((threshold * wet) + (cleanSignal * (1.f - wet)));
			else if (in < -threshold)
				out = ((-threshold * wet) + (cleanSignal * (1.f - wet)));
			else
				out = ((in * wet) + (cleanSignal * (1.f - wet)));
		}
		
		if (distortionSelect == 3) { //SoftClipping
			float threshold1 = 1.0f / 3.0f; //Thresh 1 = 1/3
			float threshold2 = 2.0f / 3.0f; // Thresh2 = 2/3
		
			
			if (in > threshold2)
				out = 1.0f;
			else if (in > threshold1)
				out = ((((3.0f - (2.0f - 3.0f * in) * (2.0f - 3.0f * in)) / 3.0f) * wet) + ((cleanSignal * (1.f - wet) / 2.f)));
			else if (in < -threshold2)
				out = -0.8f;
			else if (in < -threshold1)
				out = (((-(3.0f - (2.0f + 3.0f*in) * (2.0f + 3.0f*in)) / 3.0f) * wet) + ((cleanSignal * ((1.f - wet) / 2.f))));
			else
				out = (((1.8f* in) * wet) + ((cleanSignal * (1.f - wet) / 2.f)));
		}
		else if (distortionSelect == 4) //SoftClipping exponential
		{
			if (in > 0) 
				out = (((1.0f - expf(-in)) * wet) + ((cleanSignal * (1.f - wet) / 2.f)));
			else
				out = (((-1.0f + expf(in)) * wet) + ((cleanSignal * (1.f - wet) / 2.f)));
	
		}
		else if (distortionSelect == 5) { // Full-wave rectifier (absolute value)

			out =(((fabsf(in)) * wet) + (cleanSignal * ((1.f - wet) / 2.f)));
		}
		else if (distortionSelect == 6) { // Half-wave rectifier (absolute value)

			if (in > 0)
				out = ((in * wet) + (cleanSignal * (1.f - wet)));
			else
				out = 0;
		}
		//Put output back in buffer
		out = channelData[i] * outGain;
	}
	}
	
    }


//==============================================================================
bool SpectralDistortionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SpectralDistortionAudioProcessor::createEditor()
{

	return new SpectralDistortionAudioProcessorEditor(*this, treeState);


}

//==============================================================================
void SpectralDistortionAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	MemoryOutputStream stream(destData, true);



}

void SpectralDistortionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

	//ValueTree tree = ValueTree::readFromData(data, sizeInBytes);

	//if (tree.isValid()) {
	//
		//state->state = tree;
	//}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpectralDistortionAudioProcessor();
}



void SpectralDistortionAudioProcessor::parameterChanged(const String& parameterID, float newValue)
{
	if (parameterID == "filterCutoff")
		ladderFilter.setCutoffFrequencyHz(newValue);
	else if (parameterID == "filterResonance")
		ladderFilter.setResonance(newValue);

}

