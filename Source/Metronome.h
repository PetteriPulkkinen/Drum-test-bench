/*
  ==============================================================================

    Metronome.h
    Created: 22 Jul 2018 1:58:52pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Metronome: public AudioSource
{
public:
    Metronome();
    
    void setTempo(short tempo);
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    
    void releaseResources();
    
    void getNextAudioBlock (const AudioSourceChannelInfo &bufferToFill);
    

private:
    short tempo; // clicks per second
    double sampleRate;
    AudioBuffer<float> clickBuffer;
    int clickBufferIndex;
};
