#ifndef _IGMAINFRAME_H_
#define _IGMAINFRAME_H_

#include <TQObject.h>
#include <TRootEmbeddedCanvas.h>
#include <RQ_OBJECT.h>

class IGMainFrame{
    RQ_OBJECT("IGMainFrame")
    private:
        TGMainFrame* fMain;                 // Main window
        TRootEmbeddedCanvas* fECanvas;      // Canvas in window
    public:
        IGMainFrame(const TGWindow* window, UInt_t w, UInt_t h);
        virtual ~IGMainFrame();
        void DoDraw();
};

IGMainFrame* CreateMainFrame( UInt_t w, UInt_t h );

#endif
