#include <TApplication.h>
#include <iostream>
#include "IKCCanvas.h"
#include "IKCMainFrame.h"


int main( int argc, char** argv ){
	// Create an application
	TApplication ISS_GEOMETRY( "ISS_GEOMETRY", &argc, argv );

	// Create a main frame which contains the window (width, height)
	IKCMainFrame *mf = CreateMainFrame( 800, 600 );

	// Run application
	ISS_GEOMETRY.Run();
	return 0;
}
