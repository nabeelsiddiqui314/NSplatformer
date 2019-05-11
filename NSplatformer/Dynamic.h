#pragma once
#include "Resources.h"
#include "Animation.h"
#include "Direction.h"

class Dynamic
{
public:
	Dynamic();
	virtual ~Dynamic() {};
public:
	void setPos(const sf::Vector2f& pos);
	void setPos(float x, float y);
	void move(const sf::Vector2f& dp);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f getSize() const;

	virtual void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) {}
	virtual void interactWithOther(const Dynamic* other) {}
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window);
protected:
	void setTexture(const std::string& name);
	bool isCollidingOther(const Dynamic* other) const;
protected:
	Animation p_animation;
private:
	sf::Sprite m_body;
};