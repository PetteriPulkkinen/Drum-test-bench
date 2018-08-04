/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "GUI.h"
#include "testbench.h"
#include "Metronome.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent()
    {
        Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
        setSize (r.getWidth(), r.getHeight());

        // specify the number of input and output channels that we want to open
        setAudioChannels (1, 1);
        pgif.tb = &testbench;
        pgif.m = &metronome;
        gui.init(&pgif);
        
        addAndMakeVisible(gui);
        
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
        testbench.PrepareToRecord(sampleRate);
        metronome.prepareToPlay(samplesPerBlockExpected, sampleRate);
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        if (testbench.isRecording()){
            
            const float* inBuffer = bufferToFill.buffer->getReadPointer (0, bufferToFill.startSample);
            testbench.addBlockToBuffer(inBuffer, bufferToFill.numSamples);
        }
        metronome.getNextAudioBlock(bufferToFill);
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        setBounds(0, 0, getWidth(), getHeight());
        gui.setBounds(0, 0, getWidth(), getHeight());
    }


private:
    //==============================================================================

    // Your private member variables go here...
    TestBench testbench;
    PGIF pgif;
    GUI gui;
    Metronome metronome;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }
