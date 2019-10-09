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

		friend Color operator*(double t, const Color& color);
		friend Color operator+(const Color& lhs, const Color& rhs);

		static Color Lerp(const Color& first, const Color& second, double t);

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

