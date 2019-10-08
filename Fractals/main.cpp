#include "Bitmap.h"
#include <iostream>

using BHFractals::Bitmap;

int main() {

	const int WIDTH = 800;
	const int HEIGHT = 600;
	const std::string filename = "image.bmp";

	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999;
	double max = -999;
	for (int x = 0; x < WIDTH; ++x) {
		for (int y = 0; y < HEIGHT; ++y) {
			double xOriginal{ 2.0 * ((double)x / (double)WIDTH) - 1.0 };
			double yOriginal{ 2.0 * ((double)y / (double)HEIGHT) - 1.0 };
			if (xOriginal < min) min = xOriginal;
			if (xOriginal > max) max = xOriginal;
			if (yOriginal < min) min = yOriginal;
			if (yOriginal > max) max = yOriginal;
		}
	}

	bitmap.write(filename);

	std::cout << "Finished writing to " << filename << std::endl;
	return 0;
}