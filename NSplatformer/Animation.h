#pragma once
#include "Resources.h"

class Animation
{
public:
	void init(sf::RectangleShape* rect, const sf::Vector2i& size, const sf::Vector2i& defaultFrame);
	void animate(int row, int frames, int dt);
private:
	sf::RectangleShape* m_rect;
	sf::Vector2i m_size;
	sf::Clock m_animationClock;
	int m_column = 0;
};

