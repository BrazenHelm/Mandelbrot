#include "Bitmap.h"
#include "Color.h"
#include "Mandelbrot.h"			// edit Mandelbrot.h to adjust algorithm parameters
#include "Settings.h"			// edit Settings.h to adjust image size and position
#include <iostream>

using namespace BHFractals;

int main() {

	Bitmap bitmap(Settings::WIDTH, Settings::HEIGHT);

	Color light = Color(1.00, 0.08, 0.58);
	Color dark = Color::Black();
	Color inside = Color::Black();

	for (int x = 0; x < Settings::WIDTH; ++x) {
		if (x % 10 == 0) {
			std::cout << x << std::endl;
		}
		for (int y = 0; y < Settings::HEIGHT; ++y) {
			double xScaled = ScaleX(x);
			double yScaled = ScaleY(y);
			int iterations = Mandelbrot::getIterations(xScaled, yScaled);

			Color color = inside;
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double t = static_cast<double>(iterations) / Mandelbrot::MAX_ITERATIONS;
				color = Color::Lerp(dark, light, t);
			}
			bitmap.setPixel(x, y, color);
		}
	}

	const std::string FILENAME = "image.bmp";
	if (bitmap.write(FILENAME)) {
		std::cout << "Finished writing to " << FILENAME << std::endl;
		return 0;
	}
	else {
		std::cout << "Failed to write to " << FILENAME << std::endl;
		return 1;
	}
}
