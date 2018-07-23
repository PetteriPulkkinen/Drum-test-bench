/*
  ==============================================================================

    Metronome.h
    Created: 22 Jul 2018 1:58:52pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Metronome
{
public:
    Metronome();
    
    void setTempo(short tempo)
    {
        tempo = tempo;
    }
    
    void prepareToPlay(double sampleRate);
    
    void addBlockToBuffer(float* buffer, int numSamples);
    

private:
    short tempo; // clicks per second
    double sampleRate;
    AudioBuffer<float> clickBuffer;
    int clickBufferIndex;
};
