/*
  ==============================================================================

    Metronome.cpp
    Created: 22 Jul 2018 2:16:48pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "Metronome.h"
#include "assert.h"
#include <stdio.h>
#include <cmath>

Metronome::Metronome()
{
    File file = File("/Users/petteripulkkinen/DSP/Projects/Drum Test Bench/Resources/click2.mp3");
    jassert(file.existsAsFile());
    AudioFormatManager format_manager;
    format_manager.registerBasicFormats();
    ScopedPointer<AudioFormatReader> reader = format_manager.createReaderFor(file);
    jassert(reader!=0);
    
    clickBuffer.setSize(reader->numChannels, (int)reader->lengthInSamples);
    reader->read(&clickBuffer, 0, clickBuffer.getNumSamples(), 0, true, true);
    sampleRateFile = reader->sampleRate;
    
    tempo = 120;
    tempoSet = false;
}

void Metronome::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    clickBufferIndex = 0;
    this->sampleRate = sampleRate;
    
    this->scaleSamplingRate();
    
    this->setTempo(this->tempo);
    tempoSet = true;
}

void Metronome::getNextAudioBlock (const AudioSourceChannelInfo &bufferToFill)
{
    if (tempoSet == false)
    {
        setTempo(tempo);
    }
    for (int i = 0; i < bufferToFill.numSamples; i++)
    {
        for (int c = 0; c < bufferToFill.buffer->getNumChannels(); c++)
        {
            bufferToFill.buffer->addSample(c, i, playBuffer.getSample(0, this->clickBufferIndex));

        }
        if (clickBufferIndex + 1 >= playBuffer.getNumSamples())
        {
            clickBufferIndex = 0;
        }
        else
        {
            this->clickBufferIndex++;
        }
        
    }
}

void Metronome::releaseResources()
{
    // Must be implemented
}

void Metronome::setTempo(double tempo)
{
    this->tempo = tempo;
    int samples = 60/(double)this->tempo*this->sampleRate;
    playBuffer.clear();
    this->playBuffer.setSize(clickBuffer.getNumChannels(), samples, false);
    
    int sampleNum;
    
    if (clickBuffer.getNumSamples() > playBuffer.getNumSamples())
    {
        sampleNum = playBuffer.getNumSamples();
    }
    else
    {
        sampleNum = clickBuffer.getNumSamples();
    }
    
    for (int c = 0; c < clickBuffer.getNumChannels(); c++)
    {
        for (int i = 0; i < sampleNum; i++)
        {
            playBuffer.addSample(c, i, clickBuffer.getSample(c, i));
        }
    }
    
    if (clickBufferIndex > playBuffer.getNumSamples())
    {
        clickBufferIndex = 0;
    }
    
    this->tempoSet = true;
}

void Metronome::scaleSamplingRate()
{
    int factor = ceil(sampleRate/sampleRateFile);
    AudioBuffer<float> oldBuffer = AudioBuffer<float>(clickBuffer);
    clickBuffer.clear();
    clickBuffer.setSize(1, oldBuffer.getNumSamples() * factor);
    
    if (factor > 1)
    {
        for (int i = 0; i < oldBuffer.getNumSamples(); i++)
        {
            clickBuffer.addSample(0, i+i*(factor-1), oldBuffer.getSample(0, i));
            for (int j = 1; j < factor; j++){
                clickBuffer.addSample(0, i+i*(factor-1) + j, 0);
            }
        }
        
        // Filter out aliased components
        IIRCoefficients coefs = IIRCoefficients();
        coefs = coefs.makeLowPass(sampleRate, floor(sampleRateFile/8), 5);
        IIRFilter lpFilter = IIRFilter();
        lpFilter.setCoefficients(coefs);
        lpFilter.processSamples(clickBuffer.getWritePointer(0), clickBuffer.getNumSamples());
        
        for (int i = 0; i < clickBuffer.getNumSamples(); i++)
        {
            std::cout << clickBuffer.getSample(0, i) << std::endl;
        }
    }
    else
    {
        throw "Not implemented!";
    }
}
