#pragma once
#include "Color.h"
#include <string>

namespace BHFractals {

	struct Settings {
		int maxIterations = 100;
		int width = 800;
		int height = 800;
		double c_x = -0.5;
		double c_y = 0.0;
		double scale = 3.0;
		Color outerColor = Color::Black();
		Color edgeColor = Color::White();
		Color innerColor = Color::Black();
	};

}
