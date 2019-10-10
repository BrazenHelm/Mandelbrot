#pragma once
#include "Bitmap.h"
#include "Settings.h"
#include <string>

namespace BHFractals {

	class FractalMaker {
	private:
		Settings s;
		Bitmap bitmap;
		std::unique_ptr<int[]> histogram;
		std::unique_ptr<int[]> table;
	public:
		FractalMaker(Settings& settings);
		
		void calculateIterations();
		void drawFractal();
		bool writeBitmap(std::string filename);

		double ScaleX(int x);
		double ScaleY(int y);
	};

}
