#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	void setRect(sf::Sprite* rect);
	void setSize(const sf::Vector2i& size);
	void setSpacing(const sf::Vector2i& spacing);
	void setFrame(int row, int frame, bool lateralinversion);
	void animate(int row, int frames, int dt, bool lateralinversion);
private:
	sf::Sprite* m_rect;
	sf::Vector2i m_size;
	sf::Clock m_animationClock;
	int m_column = 0;
	sf::Vector2i m_spacing = {0,0};
};

