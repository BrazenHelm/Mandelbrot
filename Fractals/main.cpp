#include "Bitmap.h"
#include "Color.h"
#include "FractalMaker.h"
#include "Mandelbrot.h"			// edit Mandelbrot.h to adjust algorithm parameters
#include "Settings.h"			// edit Settings.h to adjust image size and position
#include <iostream>
#include <numeric>

int main() {

	BHFractals::FractalMaker fractalMaker(BHFractals::Settings::WIDTH, BHFractals::Settings::HEIGHT);

	fractalMaker.calculateIterations();
	fractalMaker.drawFractal();
	const std::string FILENAME = "image.bmp";	
	fractalMaker.writeBitmap(FILENAME);

	return 0;
}
