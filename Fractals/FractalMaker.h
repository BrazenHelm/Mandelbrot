#pragma once
#include "Bitmap.h"
#include "Settings.h"
#include <string>

namespace BHFractals {

	class FractalMaker {
	private:
		Bitmap bitmap;
		std::unique_ptr<int[]> histogram;
		std::unique_ptr<int[]> table;
	public:
		FractalMaker(int width, int height);

		void calculateIterations();
		void drawFractal();
		bool writeBitmap(std::string filename);
	};

}
