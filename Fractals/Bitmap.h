#pragma once
#include "Color.h"
#include <string>
#include <cstdint>

namespace BHFractals {

	class Bitmap {

	private:
		int m_width{ 0 };
		int m_height{ 0 };
		std::unique_ptr<uint8_t[]> m_pPixels{ nullptr };
		int DataSize();
		static const int BYTES_PER_PIXEL = 3;

	public:
		Bitmap(int width, int height);
		
		bool write(std::string filename);
		void setPixel(int x, int y, BHFractals::Color color);
	};

}
