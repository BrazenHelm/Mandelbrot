#pragma once
#include <cstdint>

namespace BHFractals {

	class Color {
	public:
		double r;
		double g;
		double b;

		Color();
		Color(double r, double g, double b);

		std::uint8_t getR255();
		std::uint8_t getG255();
		std::uint8_t getB255();





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

