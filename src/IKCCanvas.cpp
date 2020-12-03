#include "IKCCanvas.h"

IKCCanvas::IKCCanvas(){
    // Begin to exist - set initial values
    fX = new Double_t[fNum_points];
    fY = new Double_t[fNum_points];
    for ( Int_t i = 0; i < fNum_points; i++) {
        fX[i] = 0.1*i;
        fY[i] = 0.1*i*i + i + 1;
    }
}

void IKCCanvas::DrawGraph(){
    // Delete old graph if it exists
    if ( fGraph != nullptr ) {
        fGraph->Delete();
    }
    // Check you can plot on the canvas
    if ( fCanvas != nullptr ){
        fCanvas->cd();
        fGraph = new TGraph( fNum_points, fX, fY );
        fGraph->Draw("AC");
    }
}
