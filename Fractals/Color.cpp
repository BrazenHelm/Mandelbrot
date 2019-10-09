#include "Color.h"
#include <algorithm>
#include <initializer_list>

namespace BHFractals {

	Color::Color() :
		r(0), g(0), b(0) {
	}

	Color::Color(double r, double g, double b) :
		r(std::clamp(r, 0.0, 1.0)),
		g(std::clamp(g, 0.0, 1.0)),
		b(std::clamp(b, 0.0, 1.0)) {
	}

	std::uint8_t Color::getR255() { return static_cast<std::uint8_t>(r * 255 + 0.5); }
	std::uint8_t Color::getG255() { return static_cast<std::uint8_t>(g * 255 + 0.5); }
	std::uint8_t Color::getB255() { return static_cast<std::uint8_t>(b * 255 + 0.5); }

	Color operator*(double t, const Color& color) {
		return Color(t * color.r, t * color.g, t * color.b);
	}

	Color operator+(const Color& lhs, const Color& rhs) {
		return Color(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b);
	}

	Color Color::Lerp(const Color& first, const Color& second, double t) {
		if (t <= 0)
			return first;
		else if (t >= 1)
			return second;
		else
			return (1 - t) * first + t * second;
	}

	Color Color::Black() { return Color(0, 0, 0); }
	Color Color::Red() { return Color(1, 0, 0); }
	Color Color::Green() { return Color(0, 1, 0); }
	Color Color::Blue() { return Color(0, 0, 1); }
	Color Color::Cyan() { return Color(0, 1, 1); }
	Color Color::Magenta() { return Color(1, 0, 1); }
	Color Color::Yellow() { return Color(1, 1, 0); }
	Color Color::White() { return Color(1, 1, 1); }

}
