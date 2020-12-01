#include <iostream>
#include <TApplication.h>
#include <TCanvas.h>
#include <TGClient.h>
#include <TGButton.h>
#include <TGFrame.h>

#include "IGMainFrame.h"

// Override close window method
void TGMainFrame::CloseWindow(){
	// TODO - implement dialogue box that asks if they're sure
	DeleteWindow();
	gApplication->Terminate(0);
}

// Constructor
IGMainFrame::IGMainFrame(const TGWindow* window, UInt_t w, UInt_t h){
	// Create mainframe
	fMain = new TGMainFrame( window, w, h );
	ULong_t black;
	gClient->GetColorByName("black", black);

	// Create main sub frame
	TGHorizontalFrame* subframe = new TGHorizontalFrame( fMain, w, h );
	fMain->AddFrame(subframe, new TGLayoutHints( kLHintsExpandX | kLHintsExpandY, 2,2,2,2 ) );

	// Create left frame containing buttons and other options
	Int_t frame_L_width = 100;
	TGVerticalFrame *frame_L = new TGVerticalFrame( subframe, frame_L_width, h-100 );
	frame_L->ChangeOptions( kFixedWidth );
	subframe->AddFrame(frame_L, new TGLayoutHints( kLHintsLeft | kLHintsExpandY, 2,2,2,2 ) );

	// Create right frame to contain canvas
	TGVerticalFrame *frame_R = new TGVerticalFrame( subframe, ( w > frame_L_width ? w - frame_L_width : 1 ), h-100 );
	frame_R->ChangeBackground(black);
	subframe->AddFrame(frame_R, new TGLayoutHints( kLHintsRight | kLHintsExpandY | kLHintsExpandX, 2,2,2,2 ) );







	// Create canvas in right frame
	fECanvas = new TRootEmbeddedCanvas( "ECanvas", frame_R, w, h );
	frame_R->AddFrame( fECanvas, new TGLayoutHints( kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2 ) );


	// Create buttons in left frame
	TGTextButton* button_reaction = new TGTextButton( frame_L, "&Reaction" );
	//button_reaction->Connect( "Clicked()", "IGMainFrame", this, "DoDraw()" );
	frame_L->AddFrame( button_reaction, new TGLayoutHints( kLHintsLeft | kLHintsExpandX, 5, 5, 3, 4 ) );

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
}

IGMainFrame::~IGMainFrame(){
	fMain->Cleanup();
	delete fMain;
}

void IGMainFrame::DoDraw(){
	// Do something here
	std::cout << "Bananas" << std::endl;
}

IGMainFrame* CreateMainFrame( UInt_t w, UInt_t h ){
	IGMainFrame* a = new IGMainFrame( gClient->GetRoot(), w, h );
	return a;
}
