#pragma once
#include <SFML/Graphics.hpp>

struct RGB {
	int r, g, b;
	const sf::Color color() const {
		return sf::Color(r, g, b);
	}
};

namespace Data {
	struct physConsts {
		static constexpr float gravity = 1.2;
	};
	struct window {
		static constexpr int width = 992;
		static constexpr int height = 576;
	};
	struct camera {
		static constexpr int width = 992 / 2;
		static constexpr int height = 576 / 2;
		static constexpr int smoothness = 10;
		static constexpr float smallestMovement = 0.6f;
		static constexpr int foresight = 50;
	};
	struct tile {
		static constexpr int size = 32;
	};
	struct Gui {
		static constexpr int titleTopSpace = 8;
		static constexpr int titleBottomSpace = 75;
		static constexpr int leftSpace = 40;
		static constexpr int componentSpace = 5;
		static constexpr RGB title = { 224, 224, 224 };
		static constexpr RGB white = { 222, 222, 237 };
		static constexpr RGB highlighted = { 224, 98, 35 };
		static constexpr RGB box = { 128, 255, 0 };
		static constexpr RGB boxBorder = { 128, 235, 0 };
	};
}