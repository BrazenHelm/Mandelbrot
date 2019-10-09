#include "Bitmap.h"
#include "Color.h"
#include "Mandelbrot.h"
#include "Settings.h"
#include <iostream>

using namespace BHFractals;

int main() {

	Settings settings;	// edit Settings.h to adjust image size and position
	Bitmap bitmap(settings.WIDTH, settings.HEIGHT);

	Color light = Color(1.00, 0.08, 0.58);
	Color dark = Color::Black();
	Color inside = Color::Black();

	for (int x = 0; x < settings.WIDTH; ++x) {
		if (x % 10 == 0) {
			std::cout << x << std::endl;
		}
		for (int y = 0; y < settings.HEIGHT; ++y) {
			double xScaled = settings.ScaleX(x);
			double yScaled = settings.ScaleY(y);
			int iterations = Mandelbrot::getIterations(xScaled, yScaled);

			Color color = inside;
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double t = static_cast<double>(iterations) / Mandelbrot::MAX_ITERATIONS;
				color = Color::Lerp(dark, light, t);
			}
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
