#pragma once
#include <string>

namespace BHFractals {

	struct Settings {
		const std::string FILENAME = "image.bmp";
		const int WIDTH = 600;		// width of image in pixels
		const int HEIGHT = 600;	// height of image in pixels
		const double C_X = -0.5;	// x co-ordinate of centre of image
		const double C_Y = 0.0;		// y co-ordinate of centre of image
		const double ZOOM = 3.0;	// width of image in units

		double ScaleX(int x);
		double ScaleY(int y);
	};

}
