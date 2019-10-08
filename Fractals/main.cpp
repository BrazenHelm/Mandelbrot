#include "Bitmap.h"
#include "Color.h"
#include "Mandelbrot.h"
#include "Settings.h"
#include <iostream>

using namespace BHFractals;

int main() {

	Settings settings;	// edit Settings.h to adjust image settings
	settings.ShowZoom();
	std::cout << sizeof(Color);
	Bitmap bitmap(settings.WIDTH, settings.HEIGHT);

	for (int x = 0; x < settings.WIDTH; ++x) {
		if (x % 10 == 0) {
			std::cout << x << std::endl;
		}
		for (int y = 0; y < settings.HEIGHT; ++y) {
			double xScaled = settings.ScaleX(x);
			double yScaled = settings.ScaleY(y);
			int iterations = Mandelbrot::getIterations(xScaled, yScaled);
			double green = (double)iterations / Mandelbrot::MAX_ITERATIONS;
			std::uint8_t green255 = (std::uint8_t)(green * 256);
			Color color;
			color.g = green255;
			bitmap.setPixel(x, y, color);
		}
	}

	if (bitmap.write(settings.FILENAME)) {
		std::cout << "Finished writing to " << settings.FILENAME << std::endl;
		return 0;
	}
	else {
		std::cout << "Failed to write to " << settings.FILENAME << std::endl;
		return 1;
	}
}
