/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "testbench.h"
#include "Metronome.h"

typedef struct {
    TestBench* tb;
    Metronome* m;
} PGIF;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
 public Timer
                                                                    //[/Comments]
*/
class GUI  : public Component,
             public Button::Listener,
             public Slider::Listener,
             public Timer
{
public:
    //==============================================================================
    GUI ();
    ~GUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void init(PGIF* interface){
        pgif = interface;
        slider->setValue((double) pgif->tb->getN());
        slider2->setValue((double) pgif->tb->getTime());
        slider3->setValue((double) pgif->m->getTempo());
    }

    void timerCallback() override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PGIF* pgif;
    double ogtime = 0;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> textButton;
    std::unique_ptr<TextButton> textButton2;
    std::unique_ptr<Label> timenum;
    std::unique_ptr<Label> scorenum;
    std::unique_ptr<Label> highnum;
    std::unique_ptr<Slider> slider;
    std::unique_ptr<Slider> slider2;
    std::unique_ptr<TextButton> textButton3;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> slider3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
