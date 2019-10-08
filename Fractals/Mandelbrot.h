#pragma once

namespace BHFractals {

	class Mandelbrot {
	public:
		static constexpr int MAX_ITERATIONS = 200;
		static constexpr double DIVERGENCE_VALUE = 2;

		static int getIterations(double x, double y);
	};

}
