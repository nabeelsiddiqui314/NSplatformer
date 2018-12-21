#pragma once
#include <SFML/Graphics.hpp>

struct RGB {
	int r, g, b;
	const sf::Color color() const {
		return sf::Color(r, g, b);
	}
};

struct Data {
	static constexpr int windowWidth = 992;
	static constexpr int windowHeight = 576;
	static constexpr int tileSize = 32;
	static constexpr float gravity = 1.2;
	static constexpr int GUI_titleTopSpace = 8;
	static constexpr int GUI_titleBottomSpace = 75;
	static constexpr int GUI_leftSpace = 40;
	static constexpr int GUI_componentSpace = 5;
	static constexpr RGB GUI_title = { 224, 224, 224 };
	static constexpr RGB GUI_white = { 222, 222, 237 };
	static constexpr RGB GUI_highlighted = { 224, 98, 35 };
	static constexpr RGB GUI_box = { 128, 255, 0 };
	static constexpr RGB GUI_boxBorder = { 128, 235, 0 };
};