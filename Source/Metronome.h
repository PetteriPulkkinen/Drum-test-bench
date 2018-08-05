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
    
    void setTempoRequest(double tempo){this->tempo = tempo; this->tempoSet = false;}
    
    double getTempo() {return this->tempo;}
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    
    void releaseResources();
    
    void getNextAudioBlock (const AudioSourceChannelInfo &bufferToFill);
    

private:
    void setTempo(double tempo);
    void scaleSamplingRate();
    
    
    double tempo; // clicks per second
    double sampleRate;
    double sampleRateFile;
    AudioBuffer<float> clickBuffer;
    AudioBuffer<float> playBuffer;
    int clickBufferIndex;
    bool tempoSet;
};
