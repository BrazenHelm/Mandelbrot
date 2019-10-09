#include "FractalMaker.h"
#include <string>

// edit Mandelbrot.h to adjust algorithm parameters
// edit Settings.h to adjust image size and position
// edit Settings.cpp to adjust image colors

int main() {

	BHFractals::FractalMaker fractalMaker;

	fractalMaker.calculateIterations();
	fractalMaker.drawFractal();
	const std::string FILENAME = "image.bmp";	
	fractalMaker.writeBitmap(FILENAME);

	return 0;
}
