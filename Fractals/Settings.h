#pragma once
#include <string>

namespace BHFractals {

	struct Settings {
		static const int WIDTH = 600;			// width of image in pixels
		static const int HEIGHT = 600;			// height of image in pixels
		static constexpr double C_X = -0.5;		// x co-ordinate of centre of image
		static constexpr double C_Y = 0.0;		// y co-ordinate of centre of image
		static constexpr double ZOOM = 3.0;		// width of image in units

		static double ScaleX(int x);
		static double ScaleY(int y);
	};

}
