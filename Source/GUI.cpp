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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    DBG("GUI constructor");
    //[/Constructor_pre]

    textButton.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton.get());
    textButton->setButtonText (TRANS("Start"));
    textButton->addListener (this);

    textButton2.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton2.get());
    textButton2->setButtonText (TRANS("Calibrate"));
    textButton2->addListener (this);

    timenum.reset (new Label ("timenum",
                              TRANS("0")));
    addAndMakeVisible (timenum.get());
    timenum->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    timenum->setJustificationType (Justification::centredLeft);
    timenum->setEditable (false, false, false);
    timenum->setColour (TextEditor::textColourId, Colours::black);
    timenum->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    scorenum.reset (new Label ("scorenum",
                               TRANS("0")));
    addAndMakeVisible (scorenum.get());
    scorenum->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    scorenum->setJustificationType (Justification::centredLeft);
    scorenum->setEditable (false, false, false);
    scorenum->setColour (TextEditor::textColourId, Colours::black);
    scorenum->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    highnum.reset (new Label ("highnum",
                              TRANS("0")));
    addAndMakeVisible (highnum.get());
    highnum->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    highnum->setJustificationType (Justification::centredLeft);
    highnum->setEditable (false, false, false);
    highnum->setColour (TextEditor::textColourId, Colours::black);
    highnum->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    slider.reset (new Slider ("new slider"));
    addAndMakeVisible (slider.get());
    slider->setRange (512, 2048, 1);
    slider->setSliderStyle (Slider::LinearVertical);
    slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider->addListener (this);

    slider2.reset (new Slider ("new slider"));
    addAndMakeVisible (slider2.get());
    slider2->setRange (1, 60, 1);
    slider2->setSliderStyle (Slider::LinearVertical);
    slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider2->addListener (this);

    textButton3.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton3.get());
    textButton3->setButtonText (TRANS("Update"));
    textButton3->addListener (this);

    label.reset (new Label ("new label",
                            TRANS("Time\n"
                            "\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2.reset (new Label ("new label",
                             TRANS("Score")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3.reset (new Label ("new label",
                             TRANS("Highscore\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    slider3.reset (new Slider ("new slider"));
    addAndMakeVisible (slider3.get());
    slider3->setRange (40, 250, 1);
    slider3->setSliderStyle (Slider::LinearVertical);
    slider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider3->addListener (this);


    //[UserPreSize]

    //[/UserPreSize]

    setSize (375, 667);


    //[Constructor] You can add your own custom stuff here..

    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;
    textButton2 = nullptr;
    timenum = nullptr;
    scorenum = nullptr;
    highnum = nullptr;
    slider = nullptr;
    slider2 = nullptr;
    textButton3 = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    slider3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffc03b3b));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (proportionOfWidth (0.5000f) - (proportionOfWidth (0.2990f) / 2), proportionOfHeight (0.0949f), proportionOfWidth (0.2990f), proportionOfHeight (0.0802f));
    textButton2->setBounds (proportionOfWidth (0.7412f) - (proportionOfWidth (0.2990f) / 2), proportionOfHeight (0.8101f) - (proportionOfHeight (0.0675f) / 2), proportionOfWidth (0.2990f), proportionOfHeight (0.0675f));
    timenum->setBounds (proportionOfWidth (0.5916f), proportionOfHeight (0.2700f), 72, 24);
    scorenum->setBounds (proportionOfWidth (0.5916f), proportionOfHeight (0.3544f), 72, 24);
    highnum->setBounds (proportionOfWidth (0.5916f), proportionOfHeight (0.4388f), 72, 24);
    slider->setBounds (proportionOfWidth (0.0515f), proportionOfHeight (0.8629f) - proportionOfHeight (0.2553f), 70, proportionOfHeight (0.2553f));
    slider2->setBounds (proportionOfWidth (0.2830f), proportionOfHeight (0.8629f) - proportionOfHeight (0.2553f), 70, proportionOfHeight (0.2553f));
    textButton3->setBounds (proportionOfWidth (0.5916f), proportionOfHeight (0.6414f), proportionOfWidth (0.2990f), proportionOfHeight (0.0675f));
    label->setBounds (proportionOfWidth (0.5916f) + -50 - 72, proportionOfHeight (0.2700f) + 0, 72, 24);
    label2->setBounds (proportionOfWidth (0.5916f) + -50 - 72, proportionOfHeight (0.3544f) + 0, 72, 24);
    label3->setBounds (proportionOfWidth (0.5916f) + -50 - 103, proportionOfHeight (0.4388f) + 0, 103, 24);
    slider3->setBounds (proportionOfWidth (0.1623f), proportionOfHeight (0.2002f), proportionOfWidth (0.0593f), proportionOfHeight (0.2821f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton.get())
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        if (textButton->getButtonText() == "Start"){
            pgif->tb->startRecording();
            ogtime = 0;
            juce::String text(ogtime);
            timenum->setText(text, NotificationType::dontSendNotification);
            String stop("Stop");
            textButton->setButtonText(stop);
            startTimer(100);
        }
        else {
            pgif->tb->stopRecording();
        }

        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2.get())
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3.get())
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        pgif->tb->calculateDrumHits();
        juce::String score(pgif->tb->getCurrentScore());
        juce::String high(pgif->tb->getHighscore());
        scorenum->setText(score, NotificationType::dontSendNotification);
        highnum->setText(high, NotificationType::dontSendNotification);
        //[/UserButtonCode_textButton3]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider.get())
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        pgif->tb->setN((int)slider->getValue());
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2.get())
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        pgif->tb->setTime((int)slider2->getValue());
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3.get())
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        pgif->m->setTempoRequest(slider3->getValue());
        //[/UserSliderCode_slider3]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUI::timerCallback()
{
    if (pgif->tb->isRecording()){
        ogtime += 0.1;
        juce::String text(ogtime);

        timenum->setText(text, NotificationType::dontSendNotification);
    }
    else {
        ogtime += 0.1;
        juce::String text(ogtime);

        timenum->setText(text, NotificationType::dontSendNotification);
        stopTimer();

        juce::String hc(pgif->tb->getHighscore());
        juce::String s(pgif->tb->getCurrentScore());

        highnum->setText(hc, NotificationType::dontSendNotification);
        scorenum->setText(s, NotificationType::dontSendNotification);

        String start("Start");
        textButton->setButtonText(start);
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="375"
                 initialHeight="667">
  <BACKGROUND backgroundColour="ffc03b3b"/>
  <TEXTBUTTON name="new button" id="20981b42f581d91a" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="49.962%c 9.443% 29.902% 7.964%"
              buttonText="Start" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e4b5af20fb96c98" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="74.08%c 81.058%c 29.902% 6.712%"
              buttonText="Calibrate" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="timenum" id="e6cc714430292fb2" memberName="timenum" virtualName=""
         explicitFocusOrder="0" pos="59.128% 26.962% 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <LABEL name="scorenum" id="ea0d6984061c4288" memberName="scorenum" virtualName=""
         explicitFocusOrder="0" pos="59.128% 35.495% 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <LABEL name="highnum" id="75ba19dea2e0aced" memberName="highnum" virtualName=""
         explicitFocusOrder="0" pos="59.128% 43.914% 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="d91aea79d68904bd" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="5.109% 86.234%r 70 25.484%" min="512.00000000000000000000"
          max="2048.00000000000000000000" int="1.00000000000000000000"
          style="LinearVertical" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f1bc1b479f2d8ae3" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="28.325% 86.234%r 70 25.484%"
          min="1.00000000000000000000" max="60.00000000000000000000" int="1.00000000000000000000"
          style="LinearVertical" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <TEXTBUTTON name="new button" id="304faab1a0cf478d" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="59.128% 64.164% 29.902% 6.712%"
              buttonText="Update" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="bebf8d8538b240af" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="-50r 0 72 24" posRelativeX="e6cc714430292fb2"
         posRelativeY="e6cc714430292fb2" edTextCol="ff000000" edBkgCol="0"
         labelText="Time&#10;&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a2dd0ac2df5fb62c" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="-50r 0 72 24" posRelativeX="ea0d6984061c4288"
         posRelativeY="ea0d6984061c4288" edTextCol="ff000000" edBkgCol="0"
         labelText="Score" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fc76363732d0a922" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="-50r 0 103 24" posRelativeX="75ba19dea2e0aced"
         posRelativeY="75ba19dea2e0aced" edTextCol="ff000000" edBkgCol="0"
         labelText="Highscore&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="da3efcf980734916" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="16.228% 20.023% 5.935% 28.214%"
          min="40.00000000000000000000" max="250.00000000000000000000"
          int="1.00000000000000000000" style="LinearVertical" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
