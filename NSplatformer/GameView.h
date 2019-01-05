#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"

class GameView
{
public:
	void setSize(const sf::Vector2f& size);
	void setWorldSize(const sf::Vector2f& size);
	void moveCamera(const sf::Vector2f& deltaPos);
	void setView(sf::RenderWindow& window);
	bool isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const;
private:
	sf::View m_view;
	sf::Vector2f m_size;
	sf::Vector2f m_worldSize;
};

