#include "FractalMaker.h"
#include "Mandelbrot.h"
#include "Settings.h"
#include <iostream>
#include <numeric>

namespace BHFractals {

	FractalMaker::FractalMaker() :
		bitmap(Settings::WIDTH, Settings::HEIGHT),
		histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 }),
		table(new int[Settings::WIDTH * Settings::HEIGHT]) {
	}
	
	
	void FractalMaker::calculateIterations() {

		int progress = 0;
		for (int x = 0; x < Settings::WIDTH; ++x) {		
			if (100 * x / Settings::WIDTH > progress) {
				++progress;
				std::cout << progress << "% complete" << std::endl;
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

	}


	void FractalMaker::drawFractal() {

		for (int x = 0; x < Settings::WIDTH; ++x) {
			for (int y = 0; y < Settings::HEIGHT; ++y) {
				int iterations = table[x + y * Settings::WIDTH];
				Color color = Settings::COLOR_INSIDE;

				if (iterations != Mandelbrot::MAX_ITERATIONS) {
					double t = static_cast<double>(histogram[iterations]) / histogram[Mandelbrot::MAX_ITERATIONS - 1];
					t = pow(255, t) / 255;
					color = Color::Lerp(Settings::COLOR_DARK, Settings::COLOR_LIGHT, t);
				}

				bitmap.setPixel(x, y, color);
			}
		}

	}


	bool FractalMaker::writeBitmap(std::string filename) {
		if (bitmap.write(filename)) {
			std::cout << "Finished writing to " << filename << std::endl;
			return true;
		}
		else {
			std::cout << "Failed to write to " << filename << std::endl;
			return false;
		}
	}

}
