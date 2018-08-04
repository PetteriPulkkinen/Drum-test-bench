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

Metronome::Metronome()
{
    File file = File("/Users/petteripulkkinen/DSP/Projects/Drum Test Bench/Resources/click.wav");
    jassert(file.existsAsFile());
    AudioFormatManager format_manager;
    format_manager.registerBasicFormats();
    ScopedPointer<AudioFormatReader> reader = format_manager.createReaderFor(file);
    jassert(reader!=0);
    
    clickBuffer.setSize(reader->numChannels, (int)reader->lengthInSamples);
    reader->read(&clickBuffer, 0, clickBuffer.getNumSamples(), 0, true, true);
    
    tempo = 120;
}

void Metronome::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    clickBufferIndex = 0;
    this->sampleRate = sampleRate;
    int samples = 60/(double)this->tempo*this->sampleRate;
    clickBuffer.setSize(clickBuffer.getNumChannels(), samples, true);
}

void Metronome::getNextAudioBlock (const AudioSourceChannelInfo &bufferToFill)
{
    for (int c = 0; c < bufferToFill.buffer->getNumChannels(); c++)
    {
        for (int i = 0; i < bufferToFill.numSamples; i++)
        {
            bufferToFill.buffer->addSample(c, i, this->clickBuffer.getSample(0, this->clickBufferIndex));
            if (clickBufferIndex + 1 == clickBuffer.getNumSamples())
            {
                clickBufferIndex = 0;
            }
            else
            {
                this->clickBufferIndex++;
            }
            
        }
    }
}

void Metronome::releaseResources()
{
    // Must be implemented
}
