#pragma once
#include "Entity.h"

class WorldObj
{
public:
	virtual ~WorldObj() {}
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window);
	virtual void entityInteract(Entity* entity) {}
protected:
	bool isCollidingEntity(Entity* entity) const;
protected:
	void setTexture(const std::string& name);
	void setSize(const sf::Vector2f& size);
protected:
	Animation m_animation;
private:
	sf::RectangleShape m_body;
};

