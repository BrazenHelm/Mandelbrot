#include "Bitmap.h"
#include "Color.h"
#include "Mandelbrot.h"			// edit Mandelbrot.h to adjust algorithm parameters
#include "Settings.h"			// edit Settings.h to adjust image size and position
#include <iostream>
#include <numeric>

using namespace BHFractals;

int WriteFile(std::string filename, Bitmap& bitmap);

int main() {

	Bitmap bitmap(Settings::WIDTH, Settings::HEIGHT);

	//Color light = Color(1.00, 0.08, 0.58);
	Color light = Color::Green();
	Color dark = Color::Black();
	Color inside = Color::Black();

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 });
	std::unique_ptr<int[]> table(new int[Settings::WIDTH * Settings::HEIGHT]);

	for (int x = 0; x < Settings::WIDTH; ++x) {
		if (x % 10 == 0) {
			std::cout << x << std::endl;
		}
		for (int y = 0; y < Settings::HEIGHT; ++y) {
			double xScaled = ScaleX(x);
			double yScaled = ScaleY(y);
			int iterations = Mandelbrot::getIterations(xScaled, yScaled);
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				++histogram[iterations];
			}
			table[x + y * Settings::WIDTH] = iterations;
		}
	}

	for (int i = Mandelbrot::MAX_ITERATIONS - 1; i >= 0; --i) {
		histogram[i] = std::accumulate(histogram.get(), histogram.get() + i + 1, 0);
	}

	for (int x = 0; x < Settings::WIDTH; ++x) {
		for (int y = 0; y < Settings::HEIGHT; ++y) {
			int iterations = table[x + y * Settings::WIDTH];

			Color color = inside;
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				//double t = static_cast<double>(iterations) / Mandelbrot::MAX_ITERATIONS;
				double t = static_cast<double>(histogram[iterations]) / histogram[Mandelbrot::MAX_ITERATIONS - 1];
				t = pow(255, t) / 255;
				color = Color::Lerp(dark, light, t);
			}
			bitmap.setPixel(x, y, color);
		}
	}

	const std::string FILENAME = "image.bmp";
	return WriteFile(FILENAME, bitmap);
}

int WriteFile(std::string filename, Bitmap& bitmap) {
	if (bitmap.write(filename)) {
		std::cout << "Finished writing to " << filename << std::endl;
		return 0;
	}
	else {
		std::cout << "Failed to write to " << filename << std::endl;
		return 1;
	}
}
