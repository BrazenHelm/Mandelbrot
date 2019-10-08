#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>

using BHFractals::BitmapFileHeader;
using BHFractals::BitmapInfoHeader;
using std::uint8_t;

namespace BHFractals {

	int Bitmap::DataSize() {
		return m_width * m_height * 3;
	}

	Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height),
		m_pPixels(new uint8_t[width * height * 3]{ 0 }) {
	};

	bool Bitmap::write(std::string filename) {
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
		fileHeader.fileSize = fileHeader.dataOffset + DataSize();

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file{ filename, std::ios::binary };
		if (!file.is_open()) {
			return false;
		}

		file.write(reinterpret_cast<char*>(&fileHeader), sizeof(BitmapFileHeader));
		file.write(reinterpret_cast<char*>(&infoHeader), sizeof(BitmapInfoHeader));
		file.write(reinterpret_cast<char*>(m_pPixels.get()), DataSize());

		file.close();
		if (file.is_open()) {
			return false;
		}
		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* pPixel = m_pPixels.get();
		pPixel += 3 * (x + y * m_width);

		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

}
