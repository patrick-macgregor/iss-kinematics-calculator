#ifndef _IGCANVAS_H_
#define _IGCANVAS_H_

#include <TCanvas.h>
#include <TGraph.h>

class IGCanvas{
    private:
        TCanvas* fCanvas;
        TGraph* fGraph;
        Int_t num_points;
        Int_t* x;
        Int_t* y;


    public:
        IGCanvas();
        ~IGCanvas();
        

};


#endif
