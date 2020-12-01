#include <TApplication.h>
#include <iostream>
#include "IGCanvas.h"
#include "IGMainFrame.h"


int main( int argc, char** argv ){
	// Create an application
	TApplication ISS_GEOMETRY( "ISS_GEOMETRY", &argc, argv );

	// Create a main frame which contains the window (width, height)
	IGMainFrame* mf = CreateMainFrame( 800, 600 );

	// Run application
	ISS_GEOMETRY.Run();
	return 0;
}
