/*
  ==============================================================================

    CustomDragAndDrop.cpp
    Created: 8 Oct 2016 1:05:25pm
    Author:  Lindley P Cannon Jr

  ==============================================================================
*/

#include "CustomDragAndDrop.h"
class DragAndDropDemoTarget : public Component,
                                  public DragAndDropTarget,
                                  public FileDragAndDropTarget,
                                  public TextDragAndDropTarget
    {
    public:
        DragAndDropDemoTarget()
            : message ("Drag-and-drop some rows from the top-left box onto this component!\n\n"
                       "You can also drag-and-drop files and text from other apps"),
              somethingIsBeingDraggedOver (false)
        {
        }

        void paint (Graphics& g) override
        {
            g.fillAll (Colours::green.withAlpha (0.2f));

            // draw a red line around the comp if the user's currently dragging something over it..
            if (somethingIsBeingDraggedOver)
            {
                g.setColour (Colours::red);
                g.drawRect (getLocalBounds(), 3);
            }

            g.setColour (Colours::black);
            g.setFont (14.0f);
            g.drawFittedText (message, getLocalBounds().reduced (10, 0), Justification::centred, 4);
        }

        //==============================================================================
        // These methods implement the DragAndDropTarget interface, and allow our component
        // to accept drag-and-drop of objects from other Juce components..

        bool isInterestedInDragSource (const SourceDetails& /*dragSourceDetails*/) override
        {
            // normally you'd check the sourceDescription value to see if it's the
            // sort of object that you're interested in before returning true, but for
            // the demo, we'll say yes to anything..
            return true;
        }

        void itemDragEnter (const SourceDetails& /*dragSourceDetails*/) override
        {
            somethingIsBeingDraggedOver = true;
            repaint();
        }

        void itemDragMove (const SourceDetails& /*dragSourceDetails*/) override
        {
        }

        void itemDragExit (const SourceDetails& /*dragSourceDetails*/) override
        {
            somethingIsBeingDraggedOver = false;
            repaint();
        }

        void itemDropped (const SourceDetails& dragSourceDetails) override
        {
            message = "Items dropped: " + dragSourceDetails.description.toString();

            somethingIsBeingDraggedOver = false;
            repaint();
        }

        //==============================================================================
        // These methods implement the FileDragAndDropTarget interface, and allow our component
        // to accept drag-and-drop of files..

        bool isInterestedInFileDrag (const StringArray& /*files*/) override
        {
            // normally you'd check these files to see if they're something that you're
            // interested in before returning true, but for the demo, we'll say yes to anything..
            return true;
        }

        void fileDragEnter (const StringArray& /*files*/, int /*x*/, int /*y*/) override
        {
            somethingIsBeingDraggedOver = true;
            repaint();
        }

        void fileDragMove (const StringArray& /*files*/, int /*x*/, int /*y*/) override
        {
        }

        void fileDragExit (const StringArray& /*files*/) override
        {
            somethingIsBeingDraggedOver = false;
            repaint();
        }

        void filesDropped (const StringArray& files, int /*x*/, int /*y*/) override
        {
            message = "Files dropped: " + files.joinIntoString ("\n");

            somethingIsBeingDraggedOver = false;
            repaint();
        }

        //==============================================================================
        // These methods implement the TextDragAndDropTarget interface, and allow our component
        // to accept drag-and-drop of text..

        bool isInterestedInTextDrag (const String& /*text*/) override
        {
            return true;
        }

        void textDragEnter (const String& /*text*/, int /*x*/, int /*y*/) override
        {
            somethingIsBeingDraggedOver = true;
            repaint();
        }

        void textDragMove (const String& /*text*/, int /*x*/, int /*y*/) override
        {
        }

        void textDragExit (const String& /*text*/) override
        {
            somethingIsBeingDraggedOver = false;
            repaint();
        }

        void textDropped (const String& text, int /*x*/, int /*y*/) override
        {
            message = "Text dropped:\n" + text;

            somethingIsBeingDraggedOver = false;
            repaint();
        }

    private:
        String message;
        bool somethingIsBeingDraggedOver;
    };

    //==============================================================================
    ListBox sourceListBox;
    SourceItemListboxContents sourceModel;
    DragAndDropDemoTarget target;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DragAndDropDemo)