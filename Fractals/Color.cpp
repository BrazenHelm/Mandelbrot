#include "Color.h"

namespace BHFractals {

	Color::Color() :
		r(0), g(0), b(0) {
	}

	Color::Color(double r, double g, double b) :
		r(r), g(g), b(b) {
	}

	std::uint8_t Color::getR255() {
		return static_cast<std::uint8_t>(r * 255 + 0.5);
	}
	std::uint8_t Color::getG255() {
		return static_cast<std::uint8_t>(g * 255 + 0.5);
	}
	std::uint8_t Color::getB255() {
		return static_cast<std::uint8_t>(b * 255 + 0.5);
	}






	Color Color::Black() { return Color(0, 0, 0); }
	Color Color::Red() { return Color(255, 0, 0); }
	Color Color::Green() { return Color(0, 255, 0); }
	Color Color::Blue() { return Color(0, 0, 255); }
	Color Color::Cyan() { return Color(0, 255, 255); }
	Color Color::Magenta() { return Color(255, 0, 255); }
	Color Color::Yellow() { return Color(255, 255, 0); }
	Color Color::White() { return Color(255, 255, 255); }

}
