#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "Data.h"
#include "Direction.h"

class GameView
{
public:
	void setPos(const sf::Vector2f& pos);
	void setSize(const sf::Vector2f& size);
	void setWorldSize(const sf::Vector2i& size);
	void setFocus(const xDirection& dir);
	void moveCamera(const sf::Vector2f& playerPos, bool isJumping);
	const sf::Vector2f getVelocity() const;
	const sf::View& getView() const;
	bool isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const;
private:
	sf::View m_view;
	sf::Vector2f m_oldCentre;
	sf::Vector2f m_camSize;
	sf::Vector2i m_worldSize;
	xDirection m_playerDir;
};

