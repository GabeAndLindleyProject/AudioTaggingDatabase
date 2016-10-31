/*
  ==============================================================================

    CustomWindow.h
    Created: 30 Oct 2016 5:51:35pm
    Author:  Lindley P Cannon Jr

  ==============================================================================
*/

#ifndef CUSTOMWINDOW_H_INCLUDED
#define CUSTOMWINDOW_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomMenuBar.h"


class CustomWindow : public Component
{
public:
    CustomWindow()
    {
        addAndMakeVisible (textEditor1);
        textEditor1.setBounds (10, 35, 200, 24);
        textEditor1.setText ("Single-line text box");
        
        addAndMakeVisible (textEditor2);
        textEditor2.setBounds (10, 65, 200, 24);
        textEditor2.setText ("Password");
        
        addAndMakeVisible (comboBox);
        comboBox.setBounds (10, 95, 200, 24);
        comboBox.setEditableText (true);
        comboBox.setJustificationType (Justification::centred);
        
        sideItemA.setColour (TextButton::buttonColourId, Colours::wheat);
        sideItemB.setColour (TextButton::buttonColourId, Colours::wheat);
        sideItemC.setColour (TextButton::buttonColourId, Colours::wheat);
        sideItemA.setButtonText ("Add Song");
        sideItemB.setButtonText ("Delete Song");
        sideItemC.setButtonText ("Play Song");
        addAndMakeVisible (sideItemA);
        addAndMakeVisible (sideItemB);
        addAndMakeVisible (sideItemC);
    }
    ~CustomWindow() {}
    
    void resized()
    {
        Rectangle<int> area (getLocalBounds());
        Rectangle<int> sideBarArea (area.removeFromRight (jmax (80, area.getWidth() / 4)-5));
        
        
        const int sideItemHeight = 40;
        const int sideItemMargin = 5;
        sideItemA.setBounds (sideBarArea.removeFromTop (sideItemHeight).reduced (sideItemMargin));
        sideItemB.setBounds (sideBarArea.removeFromTop (sideItemHeight).reduced (sideItemMargin));
        sideItemC.setBounds (sideBarArea.removeFromTop (sideItemHeight).reduced (sideItemMargin));
    }

    
private:
    TextEditor textEditor1, textEditor2;
    ComboBox comboBox;
    TextButton sidebar;
    TextButton sideItemA; // [3]
    TextButton sideItemB; // [4]
    TextButton sideItemC; // [5]
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomWindow)
};


#endif  // CUSTOMWINDOW_H_INCLUDED
