#include <GL/glut.h>
#include <stdio.h>
#include "../../include/Graphics/Graphics.h"
#include "../../include/CarromRules/Board.h"
		
// Called when the window is resized
//		w, h - width and height of the window in pixels.
void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;
	// Define the portion of the window used for OpenGL rendering.
	glViewport( 0, 0, w, h );	// View port uses whole window

	// Set up the projection view matrix: orthographic projection
	// Determine the min and max values for x and y that should appear in the window.
	// The complication is that the aspect ratio of the window may not match the
	//		aspect ratio of the scene we want to view.
	w = (w==0) ? 1 : w;
	h = (h==0) ? 1 : h;
	if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
		scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
		center = (Xmax+Xmin)/2;
		windowXmin = center - (center-Xmin)*scale;
		windowXmax = center + (Xmax-center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
		if(DEBUG)
			printf("%f %f %f %f from Resize\n",scale,center,windowXmin,windowXmax);
	}
	else {
		scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
		center = (Ymax+Ymin)/2;
		windowYmin = center - (center-Ymin)*scale;
		windowYmax = center + (Ymax-center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}
	
	// Now that we know the max & min values for x & y that should be visible in the window,
	//		we set up the orthographic projection.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -0., 1 );
if(data->w1==0&&data->w2==0)
{
data->w1=w;
data->w2=h;
}	
	{

	data->conversiony=(Xmax-Xmin)/(w);
	data->conversiony=(Ymax-Ymin)/h;
	
}
if((Xmax-Xmin)/(w)>(Ymax-Ymin)/h)
data->conversiony-=.0000000033;
if((Xmax-Xmin)/(w)<(Ymax-Ymin)/h)
data->conversiony+=.0001033;


}

