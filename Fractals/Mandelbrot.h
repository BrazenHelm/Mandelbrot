#pragma once

namespace BHFractals {

	class Mandelbrot {
	public:
		static constexpr double DIVERGENCE_VALUE = 2;

		static int getIterations(double x, double y, int maxIterations);
	};

}
