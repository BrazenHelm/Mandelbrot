#include "Settings.h"
#include <iostream>

namespace BHFractals {

	double Settings::ScaleX(int x) {
		double a = ZOOM / (WIDTH - 1);
		double b = C_X - (ZOOM / 2);
		return a * x + b;
	}

	double Settings::ScaleY(int y) {
		double yZoom = ZOOM * HEIGHT / WIDTH;
		double a = yZoom / (HEIGHT - 1);
		double b = C_Y - (yZoom / 2);
		return a * y + b;
	}

}
