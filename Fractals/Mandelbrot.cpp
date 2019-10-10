#include "Mandelbrot.h"
#include <complex>

namespace BHFractals {

	int Mandelbrot::getIterations(double x, double y, int maxIterations) {

		std::complex<double> z{ 0, 0 };
		std::complex<double> c{ x, y };

		int iterations = 0;
		while (iterations < maxIterations && std::abs(z) <= DIVERGENCE_VALUE) {
			z = z * z + c;
			++iterations;
		}
		return iterations;
	}

}
