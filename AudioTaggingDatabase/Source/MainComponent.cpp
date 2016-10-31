/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    addAndMakeVisible (menu);
    addAndMakeVisible (window);
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    
}

void MainContentComponent::resized()
{
    menu.setBounds( getLocalBounds() );
    window.setBounds ( getLocalBounds() );
}
