#include "FractalMaker.h"
#include "Mandelbrot.h"
#include "Settings.h"
#include <iostream>
#include <numeric>

namespace BHFractals {

	FractalMaker::FractalMaker(Settings& settings) :
		bitmap(settings.width, settings.height),
		histogram(new int[settings.maxIterations]{ 0 }),
		table(new int[settings.width * settings.height]),
		s(settings) {
	}
	
	
	void FractalMaker::calculateIterations() {

		int progress = 0;
		for (int x = 0; x < s.width; ++x) {		
			if (100 * x / s.width > progress) {
				++progress;
				std::cout << progress << "% complete" << std::endl;
			}
			for (int y = 0; y < s.height; ++y) {
				double xScaled = ScaleX(x);
				double yScaled = ScaleY(y);
				int iterations = Mandelbrot::getIterations(xScaled, yScaled, s.maxIterations);
				if (iterations != s.maxIterations) {
					++histogram[iterations];
				}
				table[x + y * s.width] = iterations;
			}
		}

		for (int i = s.maxIterations - 1; i >= 0; --i) {
			histogram[i] = std::accumulate(histogram.get(), histogram.get() + i + 1, 0);
		}

	}


	void FractalMaker::drawFractal() {

		for (int x = 0; x < s.width; ++x) {
			for (int y = 0; y < s.height; ++y) {
				int iterations = table[x + y * s.width];
				Color color = s.innerColor;

				if (iterations != s.maxIterations) {
					double t = static_cast<double>(histogram[iterations]) / histogram[s.maxIterations - 1];
					t = pow(255, t) / 255;
					color = Color::Lerp(s.outerColor, s.edgeColor, t);
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


	double FractalMaker::ScaleX(int x) {
		double a = s.scale / (s.width - 1);
		double b = s.c_x - (s.scale / 2);
		return a * x + b;
	}


	double FractalMaker::ScaleY(int y) {
		double yScale = s.scale * s.height / s.width;
		double a = yScale / (s.height - 1);
		double b = s.c_y - (yScale / 2);
		return a * y + b;
	}

}
