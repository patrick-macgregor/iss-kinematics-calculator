#ifndef _IKCCANVAS_H_
#define _IKCCANVAS_H_

#include <iostream>
#include <TCanvas.h>
#include <TGraph.h>

class IKCCanvas{
    private:
        TCanvas *fCanvas = nullptr;
        TGraph *fGraph = nullptr;
        const Int_t fNum_points = 900;
        Double_t *fX = nullptr;
        Double_t *fY = nullptr;
        Double_t fX_lb = 0.0;
        Double_t fY_lb = 90.0;


    public:
        IKCCanvas();
        ~IKCCanvas();
        void DrawGraph();

        // Setters
        void SetX( Double_t *x ){ fX = x; }
        void SetY( Double_t *y ){ fY = y; }
        void SetCanvas( TCanvas *c ){ fCanvas = c; }

        // Getters
        TCanvas *GetCanvas(){ return fCanvas; }
        TGraph *GetGraph(){ return fGraph; }
        Double_t *GetX(){ return fX; }
        Double_t *GetY(){ return fY; }
        Double_t GetXLB(){ return fX_lb; }
        Double_t GetYLB(){ return fY_lb; }
};


#endif
