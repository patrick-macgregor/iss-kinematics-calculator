#include <iostream>
#include <TApplication.h>
#include <TCanvas.h>
#include <TGClient.h>
#include <TGFrame.h>


#include "IKCMainFrame.h"


// Override close window method
void TGMainFrame::CloseWindow(){
	// TODO - implement dialogue box that asks if they're sure
	DeleteWindow();
	gApplication->Terminate(0);
}

// Constructor
IKCMainFrame::IKCMainFrame(const TGWindow *window, UInt_t w, UInt_t h){
	// Create mainframe
	fMain = new TGMainFrame( window, w, h );

	// Initialise the window
	DrawGUI( w, h );
	ConnectInputsToOutputs();

	// Set name of window
	fMain->SetWindowName("ISS Kinematics Calculator");

	// Map subwindows
	fMain->MapSubwindows();

	// Initialise the layout algorithm
	fMain->Resize(fMain->GetDefaultSize());

	// Set minimum size limits
	fMain->SetWMSizeHints(400, 200, 1E7, 1E7, 1, 1);

	// Map main mainframe
	fMain->MapWindow();

	return;
}

// DRAW THE GUI IN USE
void IKCMainFrame::DrawGUI( UInt_t w, UInt_t h ){
	// Define colours
	ULong_t black;
	gClient->GetColorByName("black", black);

	// Create main sub frame
	TGHorizontalFrame *subframe = new TGHorizontalFrame( fMain, w, h );
	fMain->AddFrame(subframe, new TGLayoutHints( kLHintsExpandX | kLHintsExpandY, 2,2,2,2 ) );

	// Create left frame containing buttons and other options
	Int_t frame_L_width = 150;
	TGVerticalFrame *frame_L = new TGVerticalFrame( subframe, frame_L_width, h );
	frame_L->ChangeOptions( kFixedWidth );
	subframe->AddFrame(frame_L, new TGLayoutHints( kLHintsLeft | kLHintsExpandY, 2,2,2,2 ) );

	// Create right frame to contain canvas
	TGVerticalFrame *frame_R = new TGVerticalFrame( subframe, ( w > frame_L_width ? w - frame_L_width : 1 ), h );
	frame_R->ChangeBackground(black);
	subframe->AddFrame(frame_R, new TGLayoutHints( kLHintsRight | kLHintsExpandY | kLHintsExpandX, 2,2,2,2 ) );

	// RIGHT HAND PANEL
	fECanvas = new TRootEmbeddedCanvas( "ECanvas", frame_R, w, h );
	frame_R->AddFrame( fECanvas, new TGLayoutHints( kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2 ) );

	// Initialise the canvas and draw it
	fIKCCanvas = new IKCCanvas();
	fIKCCanvas->SetCanvas( fECanvas->GetCanvas() );
	fIKCCanvas->DrawGraph();


	// LEFT HAND PANEL
	// Reaction button
	fButton_reaction = new TGTextButton( frame_L, "&Reaction" );
	frame_L->AddFrame( fButton_reaction, new TGLayoutHints( kLHintsLeft | kLHintsExpandX, 5, 5, 3, 4 ) );

	// Graph limit boxes
	fGF_GraphSettings = new TGGroupFrame( frame_L, "Graph Settings" );
	frame_L->AddFrame( fGF_GraphSettings, new TGLayoutHints( kLHintsLeft | kLHintsExpandX, 5, 5, 3, 4 ) );
	fGF_GraphSettings->SetTitlePos( TGGroupFrame::kLeft );
		fL_GraphXLowerBound = new TGLabel( fGF_GraphSettings, "Lower Bound" );
		fGF_GraphSettings->AddFrame( fL_GraphXLowerBound, new TGLayoutHints( kLHintsLeft, 1, 1, 1, 1 ) );
		fNE_GraphXLowerBound = new TGNumberEntry( fGF_GraphSettings, 0, 9,999, TGNumberFormat::kNESInteger, TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 99999 );
		fGF_GraphSettings->AddFrame( fNE_GraphXLowerBound, new TGLayoutHints( kLHintsLeft | kLHintsExpandX, 5, 5, 3, 4 ) );

		fL_GraphXUpperBound = new TGLabel( fGF_GraphSettings, "Upper Bound" );
		fGF_GraphSettings->AddFrame( fL_GraphXUpperBound, new TGLayoutHints( kLHintsLeft, 1, 1, 1, 1 ) );
		fNE_GraphXUpperBound = new TGNumberEntry( fGF_GraphSettings, 0, 9,999, TGNumberFormat::kNESInteger, TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 99999 );
		fGF_GraphSettings->AddFrame( fNE_GraphXUpperBound, new TGLayoutHints( kLHintsLeft | kLHintsExpandX, 5, 5, 3, 4 ) );

		fL_GraphXSpacing = new TGLabel(fGF_GraphSettings, "Spacing");
		fGF_GraphSettings->AddFrame(fL_GraphXSpacing, new TGLayoutHints( kLHintsLeft, 1, 1, 1, 1 ) );
		fNE_GraphXSpacing = new TGNumberEntry( fGF_GraphSettings, 0, 9,999, TGNumberFormat::kNESInteger, TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 99999 );
		fGF_GraphSettings->AddFrame( fNE_GraphXSpacing, new TGLayoutHints( kLHintsLeft | kLHintsExpandX, 5, 5, 3, 4 ) );

	// Update buton
	fButton_update = new TGTextButton( frame_L, "&Update" );
	frame_L->AddFrame( fButton_update, new TGLayoutHints( kLHintsBottom | kLHintsExpandX, 5, 5, 3, 4 ) );


	return;
}

void IKCMainFrame::ConnectInputsToOutputs(){
	std::cout << "CONNECT BUTTONS!" << std::endl;
}






IKCMainFrame::~IKCMainFrame(){
	fMain->Cleanup();
	delete fMain;
}

void IKCMainFrame::DrawCanvas(){
	// Draw the canvas from the fed in IKCCanvas
	TCanvas *c = fIKCCanvas->GetCanvas();
	c->cd();
	c->Modified();
	c->Update();
	return;
}

IKCMainFrame *CreateMainFrame( UInt_t w, UInt_t h ){
	IKCMainFrame *a = new IKCMainFrame( gClient->GetRoot(), w, h );
	return a;
}
