#include "Settings.h"
#include <iostream>

namespace BHFractals {

	double ScaleX(int x) {
		double a = Settings::ZOOM / (Settings::WIDTH - 1);
		double b = Settings::C_X - (Settings::ZOOM / 2);
		return a * x + b;
	}

	double ScaleY(int y) {
		double yZoom = Settings::ZOOM * Settings::HEIGHT / Settings::WIDTH;
		double a = yZoom / (Settings::HEIGHT - 1);
		double b = Settings::C_Y - (yZoom / 2);
		return a * y + b;
	}

}
