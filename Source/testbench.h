/*
  ==============================================================================

    testbench.h
    Created: 24 Dec 2017 11:40:47am
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class TestBench : public Timer {
public:
    TestBench();
    ~TestBench(){}
    
    void startRecording();
    void stopRecording();
    const bool isRecording() const{
        return isOn;
    }
    
    void PrepareToRecord(double _samplerate){
        samplerate = _samplerate;
    }
    
    void timerCallback(){
        stopRecording();
    }
    
    void calculateDrumHits();
    
    float sum(AudioSampleBuffer buf, int start, int numSamples);
    
    void addBlockToBuffer(const float* source, int numSamples);
    
    const unsigned int getHighscore() const {
        return highscore;
    }
    
    const unsigned int getCurrentScore() const {
        return currentScore;
    }
    
    void clear(){
        buffer.clear();
        length = 0;
        DBG("Buffer cleared");
    }
    
    // Getters and setters
    void setN(int value){
        N = value;
    }
    
    int getN(){
        return N;
    }
    
    void setTime(int value){
        time = value;
    }
    
    int getTime(){
        return time;
    }
private:
    bool isOn;
    AudioSampleBuffer buffer;
    int length;
    int channel;
    float th;
    int time;
    double samplerate;
    unsigned int highscore;
    unsigned int currentScore;
    int N;
};
