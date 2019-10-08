#include "Mandelbrot.h"
#include <complex>
#include <iostream>

namespace BHFractals {

	int Mandelbrot::getIterations(double x, double y) {

		std::complex<double> z{ 0, 0 };
		std::complex<double> c{ x, y };

		int iterations = 0;
		while (iterations < MAX_ITERATIONS && std::abs(z) <= DIVERGENCE_VALUE) {
			z = z * z + c;
			++iterations;
		}
		return iterations;
	}

}
