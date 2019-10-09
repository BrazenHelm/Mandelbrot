#pragma once
#include <cstdint>

namespace BHFractals {

	class Color {
	public:
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;

		double red;
		double green;
		double blue;

		Color();
		Color(std::uint8_t r, std::uint8_t g, std::uint8_t b);

		static Color Black();
		static Color Red();
		static Color Green();
		static Color Blue();
		static Color Cyan();
		static Color Magenta();
		static Color Yellow();
		static Color White();
	};

}

