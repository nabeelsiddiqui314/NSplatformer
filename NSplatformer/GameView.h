#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"

class GameView
{
public:
	void setPos(const sf::Vector2f& pos);
	void setSize(const sf::Vector2f& size);
	void setWorldSize(const sf::Vector2i& size);
	void moveCamera(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Vector2f& deltaPos);
	const sf::View& getView() const;
	bool isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const;
private:
	sf::View m_view;
	sf::Vector2f m_camSize;
	sf::Vector2i m_worldSize;
};

