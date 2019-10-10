#include "Color.h"
#include "FractalMaker.h"
#include "Settings.h"
#include <string>

using BHFractals::Color;

int main() {

	BHFractals::Settings s;

	// ==== Settings ==== //
	std::string filename = "image.bmp";		// Filename of image; must end ".bmp"
	s.maxIterations = 1000;					// Maximum iterations the algorithm will perform
	s.width = 2400;							// Width of the image in pixels
	s.height = 2400;						// Height of the image in pixels
	s.c_x = -0.569;							// x co-ordinate of the centre of the image
	s.c_y = 0.489;							// y co-ordinate of the centre of the image
	s.scale = 0.05;							// Width of the image on the complex plane
	s.outerColor = Color::Black();			// Color of the background of the image
	s.edgeColor = Color::Pink();			// Color of the edge of the fractal
	s.innerColor = Color::Black();			// Color of the inside of the fractal

	BHFractals::FractalMaker fractalMaker(s);
	fractalMaker.calculateIterations();
	fractalMaker.drawFractal();
	fractalMaker.writeBitmap(filename);

	return 0;
}
