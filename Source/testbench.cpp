/*
  ==============================================================================

    testbench.cpp
    Created: 24 Dec 2017 11:40:47am
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "testbench.h"


TestBench::TestBench() : isOn(false)
{
    DBG("Testbench contructor");
    channel = 0;
    th = 0.1;
    time = 2; //in seconds
    samplerate = 0;
    length = 0;
    highscore = 0;
    currentScore = 0;
    N = 1024;
}

void TestBench::startRecording()
{
    clear();
    buffer.setSize(1, samplerate*time);
    startTimer(time*1000);
    DBG("Start recording");
    DBG("Buffer size initialized: " + juce::String(time*samplerate));
    DBG("Time set: "+juce::String(time));
    isOn = true;
}

void TestBench::stopRecording()
{
    isOn = false;
    DBG("Stop recording");
    calculateDrumHits();
    stopTimer();
}

void TestBench::calculateDrumHits(){
    
    // Energy
    AudioSampleBuffer energy = buffer;
    const float* readpointer = buffer.getReadPointer(channel);
    float* writepointer = energy.getWritePointer(channel);
    for (int i = 0; i < length; i++){
        writepointer[i] = readpointer[i]*readpointer[i];
    }
    
    // Avarage
    int nbins = (int) length/N;
    AudioSampleBuffer avarageEnergy;
    avarageEnergy.setSize(1, nbins);
    float* writepointer2 = avarageEnergy.getWritePointer(channel);
    
    int k = 0;
    for (int i = 0; i < energy.getNumSamples()-N;i++){
        if (k>=nbins){
            break;
        }
        writepointer2[k] = sum(energy,i,N);
        k += 1;
        i += N-1;
    }
    
    DBG("Avarage sumenergy: " + juce::String(sum(avarageEnergy,0,nbins)));
    
    // Drum hits
    unsigned int hits = 0;
    const float* readpointer2 = avarageEnergy.getReadPointer(channel);
    for (int i = 1; i < avarageEnergy.getNumSamples()-1; i++){
        float prev = readpointer2[i-1];
        float next = readpointer2[i+1];
        float curr = readpointer2[i];
        
        if (prev < curr && next < curr){
            if (curr > th){
                hits += 1;
            }
        }
    }
    DBG("Score: " + juce::String((int)hits));
    currentScore = hits;
    if (hits > highscore){
        highscore = hits;
    }
    avarageEnergy.clear();
    energy.clear();
}

float TestBench::sum(AudioSampleBuffer buf, int start, int numSamples){
    const float* readpointer = buf.getReadPointer(channel, start);
    float sum = 0;
    for (int i = 0; i < numSamples; i++){
        sum += readpointer[i];
    }
    return sum;
}

void TestBench::addBlockToBuffer(const float* source, int numSamples){
    float* writepointer = buffer.getWritePointer(channel);
    for (int i = 0; i < numSamples; i++){
        writepointer[i+length] = source[i];
    }
    length+=numSamples;
}
