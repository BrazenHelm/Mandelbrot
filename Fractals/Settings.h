#pragma once
#include <string>

namespace BHFractals {

	struct Settings {
		static const int WIDTH = 2400;				// width of image in pixels
		static const int HEIGHT = 2400;				// height of image in pixels
		static constexpr double C_X = -0.569;		// x co-ordinate of centre of image
		static constexpr double C_Y = 0.488;		// y co-ordinate of centre of image
		static constexpr double ZOOM = 0.05;		// width of image in units
		static const Color COLOR_LIGHT;
		static const Color COLOR_DARK;
		static const Color COLOR_INSIDE;
	};

	double ScaleX(int x);
	double ScaleY(int y);

}
