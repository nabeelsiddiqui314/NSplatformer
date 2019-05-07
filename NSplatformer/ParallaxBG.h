#pragma once
#include <array>
#include "GameView.h"
#include "Resources.h"

class ParallaxBG
{
public:
	void init(const std::string& folder, bool isFixedY);
	void update(const sf::Vector2f& playerPos, float xVelocity);
	void render(sf::RenderWindow& window);
private:
	int swap(int num);
private:
	std::array<std::vector<sf::Sprite>, 2> m_backgrounds;
	bool m_isYfixed;

};

