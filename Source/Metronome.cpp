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

void Metronome::prepareToPlay(double sampleRate)
{
    clickBufferIndex = 0;
    this->sampleRate = sampleRate;
    int samples = 60/(double)this->tempo*this->sampleRate;
    clickBuffer.setSize(clickBuffer.getNumChannels(), samples, true);
}

void Metronome::addBlockToBuffer(float* buffer, int numSamples)
{
    for (int c = 0; c < this->clickBuffer.getNumChannels(); c++)
    {
        for (int i = 0; i < numSamples; i++)
        {
            buffer[i] = this->clickBuffer.getSample(c, this->clickBufferIndex);
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
