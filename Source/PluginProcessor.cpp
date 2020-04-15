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
	), treeState(*this, nullptr, Identifier("PARAMETERS"), { std::make_unique<AudioParameterFloat>("cutoff", "Cutoff", 20.0f, 20000.0f, 20000.0f),
		std::make_unique<AudioParameterFloat>("resonance", "Resonance", 0.0f, 1.10f, 0.15f),
		 std::make_unique<AudioParameterFloat>("drive", "Drive", 1.0f, 25.0f, 1.0f),
		 std::make_unique<AudioParameterChoice>("mode", "Filter Type", StringArray("LPF12", "LPF24", "HPF12", "HPF24"), 0) })
		//std::make_unique<AudioParameterChoice>("distortionType_", "Distortion Type:", StringArray("Hard Clip", "Soft Clip", "Soft Clip Exponential", "Full-wave Rectifier", "Half-Wave Rectifier"),
		//	std::make_unique<AudioParameterChoice>("inputGain", "Distortion Type:", StringArray("Hard Clip", "Soft Clip", "Soft Clip Exponential", "Full-wave Rectifier", "Half-Wave Rectifier"), 0))) })
	
		
#endif
{
	const StringArray params = { "cutoff", "resonance", "drive", "mode" };
	for (int i = 0; i <= 3; ++i)
	{
		// adds a listener to each parameter in the array.
		treeState.addParameterListener(params[i], this);
	}
	addParameter(inputGain = new AudioParameterFloat("inputGain", "Input Gain", NormalisableRange<float>(0.0f, 10.0f), 5.0f));

	addParameter(comboChoice = new AudioParameterChoice("distortionType_",
		"Distortion Type:", { "Select one", "Hard Clip", "Soft Clip", "Soft Clip Exponential", "Full-wave Rectifier", "Half-Wave Rectifier" }, 0));
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
	previousGain = *inputGain;
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

void SpectralDistortionAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();
	int numSamples; // Number of audio samples to process
	float* channelData; //Array of samples, length numSamples
	

	//float inputGainDecibels_; //Gain in decibels, controlled by the user
	

	//Calculate input gain once to save calculations
	//inputGain = powf(10.0f, inputGainDecibels_ / 20.0f);



	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	// This is here to avoid people getting screaming feedback
	// when they first compile a plugin, but obviously you don't need to keep
	// this code if your algorithm always overwrites all the output channels.
	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	juce::dsp::AudioBlock<float> block(buffer);
	auto processingContext = dsp::ProcessContextReplacing<float>(block);
	ladderFilter.process(processingContext);

		
	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...
	// Make sure to reset the state if your inner loop is processing
	// the samples and the outer loop is handling the channels.
	// Alternatively, you can process the samples with the channels
	// interleaved by keeping the same state.
    
	
	
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);
		auto currentGain = (inputGain->get()); //Get Input Gain Value
		auto distortionType_ = comboChoice->getIndex();

		// ..do something to the data...
			for (int i = 0; i < numSamples; ++i) {

		auto in = channelData[i];
		if (currentGain == previousGain)
		{
			buffer.applyGain(currentGain);
		}
		else
		{
			buffer.applyGainRamp(0, buffer.getNumSamples(), previousGain, currentGain);
			previousGain = currentGain;
		}
	//in = in * inGain;


		if (distortionType_ == 1) { // HardClipping
			float threshold = 1.0f; // Thresh1 = 1.0

			if (in > threshold)
				in = threshold;
			else if (in < -threshold)
				in = -threshold;
			else
				in = in;
		}
		else if (distortionType_ == 2) { //SoftClipping
			float threshold1 = 1.0f / 3.0f; //Thresh 1 = 1/3
			float threshold2 = 2.0f / 3.0f; // Thresh2 = 2/3
			if (in > threshold2)
				in = 1.0f;
			else if (in > threshold1)
				in = (3.0f - (2.0f - 3.0f * in) * (2.0f - 3.0f * in)) / 3.0f;
			else if (in < -threshold2)
				in = -1.0f;
			else if (in < -threshold1)
				in = -(3.0f - (2.0f + 3.0f*in) * (2.0f + 3.0f*in)) / 3.0f;
			else
				in = 2.0f* in;
		}
		else if (distortionType_ == 3) //SoftClipping exponential
		{
			if (in > 0) 
				in = 1.0f - expf(-in);
			else
				in = -1.0f + expf(in);
			
		}
		else if (distortionType_ == 4) { // Full-wave rectifier (absolute value)

			in = fabsf(in);
		}
		else if (distortionType_ == 5) { // Half-wave rectifier (absolute value)

			if (in > 0)
				in = in;
			else
				in = 0;
		}
		//Put output back in buffer
		channelData[i] = in;
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
	stream.writeFloat(*inputGain);
	stream.writeInt(*comboChoice);
	//stream.writeInt(*comboChoice);
}

void SpectralDistortionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
	MemoryInputStream stream(data, static_cast<size_t> (sizeInBytes), false);
	inputGain->setValueNotifyingHost(inputGain->getNormalisableRange().convertTo0to1(stream.readFloat()));
	comboChoice->setValueNotifyingHost(comboChoice->getNormalisableRange().convertTo0to1(stream.readInt()));
	//comboChoice->setValueNotifyingHost(comboChoice->getNormalisableRange().convertTo0to1(stream.readInt()));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpectralDistortionAudioProcessor();
}

void SpectralDistortionAudioProcessor::parameterChanged(const String& parameterID, float newValue)
{
}
