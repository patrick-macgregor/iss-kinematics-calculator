#ifndef _IKCMAINFRAME_H_
#define _IKCMAINFRAME_H_

#include <TGButton.h>
#include <TGLabel.h>
#include <TGNumberEntry.h>
#include <TQObject.h>
#include <TRootEmbeddedCanvas.h>
#include <RQ_OBJECT.h>
#include "IKCCanvas.h"

class IKCMainFrame{
    RQ_OBJECT("IKCMainFrame")
    private:
        TGMainFrame *fMain;                 // Main window
        TRootEmbeddedCanvas *fECanvas;      // Canvas in window
        IKCCanvas *fIKCCanvas;
        TGTextButton *fButton_reaction, *fButton_update;
        TGGroupFrame *fGF_GraphSettings;
        TGNumberEntry *fNE_GraphXLowerBound, *fNE_GraphXUpperBound, *fNE_GraphXSpacing;
        TGLabel *fL_Reaction, *fL_GraphXLowerBound, *fL_GraphXUpperBound, *fL_GraphXSpacing;
    public:
        IKCMainFrame(const TGWindow *window, UInt_t w, UInt_t h);
        virtual ~IKCMainFrame();
        void DrawCanvas();
        void DrawGUI( UInt_t w, UInt_t h );
        void ConnectInputsToOutputs();
};

IKCMainFrame *CreateMainFrame( UInt_t w, UInt_t h );

#endif
