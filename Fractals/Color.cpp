#include "Color.h"

namespace BHFractals {

	Color::Color() :
		r(0), g(0), b(0) {
	}

	Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) :
		r(r), g(g), b(b) {
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
