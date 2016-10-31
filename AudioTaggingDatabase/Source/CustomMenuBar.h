/*
  ==============================================================================

    CustomMenuBar.h
    Created: 30 Oct 2016 5:55:55pm
    Author:  Lindley P Cannon Jr

  ==============================================================================
*/

#ifndef CUSTOMMENUBAR_H_INCLUDED
#define CUSTOMMENUBAR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class CustomMenuBar : public Component,
                        public MenuBarModel
{
public:
    CustomMenuBar()
    {
        addAndMakeVisible (menuBar = new MenuBarComponent (this));
    }
    
    ~CustomMenuBar() {
       #if JUCE_MAC
        MenuBarModel::setMacMainMenu (nullptr);
       #endif
        PopupMenu::dismissAllActiveMenus();
    }
    
    void resized() override
    {
        Rectangle<int> area (getLocalBounds());
        menuBar->setBounds (area.removeFromTop (LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
        
        area.removeFromTop (20);
        area = area.removeFromTop (33);
        
    }
    
    
    StringArray getMenuBarNames() override
    {
        const char* const names[] = { "File", "Something-Cool", "View", nullptr };
        
        return StringArray (names);
    }
    PopupMenu getMenuForIndex (int menuIndex, const String& /*menuName*/) override
    {
        //ApplicationCommandManager* commandManager = MainContentComponent::getApplicationCommandManager();
        
        PopupMenu menu;
        if (menuIndex == 0)
        {
            #if JUCE_MAC
            menu.addItem (0, "Hell");
            menu.addItem (1, "New Add", true, false);
            //menu.addSeparator();
            #endif
        }
        else if (menuIndex == 1)
        {
            menu.addItem (0, "Sue Me", true, false);
        }
        return menu;
    }
    
    void menuItemSelected (int menuItemID, int ) override
    {
        if (menuItemID == 0)
        {
            #if JUCE_MAC
            if (MenuBarModel::getMacMainMenu() != nullptr)
            {
                MenuBarModel::setMacMainMenu (nullptr);
                menuBar->setModel (this);
            }
            else
            {
                menuBar->setModel (nullptr);
                MenuBarModel::setMacMainMenu (this);
            }
            #endif
        }
    }
    //==============================================================================

    
protected:
    ScopedPointer<MenuBarComponent> menuBar;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomMenuBar)
};



#endif  // CUSTOMMENUBAR_H_INCLUDED
