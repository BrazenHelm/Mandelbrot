#pragma once
#include "Bitmap.h"
#include <string>

namespace BHFractals {

	class FractalMaker {
	private:
		Bitmap bitmap;
		std::unique_ptr<int[]> histogram;
		std::unique_ptr<int[]> table;
	public:
		FractalMaker();

		void calculateIterations();
		void drawFractal();
		bool writeBitmap(std::string filename);
	};

}
