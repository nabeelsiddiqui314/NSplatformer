#pragma once
#include "Resources.h"
#include "Animation.h"
#include "AnimationParser.h"
#include "Direction.h"

class DynamicManager;

class Dynamic
{
public:
	Dynamic(const std::string& name);
	virtual ~Dynamic() {};
public:
	void setPos(const sf::Vector2f& pos);
	void setPos(float x, float y);
	void move(const sf::Vector2f& dp);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f getSize() const;
	void setTextureRect(const sf::IntRect& rect, const sf::Vector2f& constPoint);
	void setDynamicManager(DynamicManager* dm);
	void addObject(Dynamic* newObj, const sf::Vector2f& pos);
	bool isDestroyed() const;
	bool isFriendly() const;
	int getID() const;

	virtual void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) {}
	virtual void interactWithOther(Dynamic* other) {}
	virtual void takeDamage(int amount) {}
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window);
protected:
	bool isCollidingOther(const Dynamic* other) const;
	void destroy();
protected:
	Animation p_animation;
	bool p_isFriendly = true;
	int p_id;
private:
	sf::Sprite m_body;
	DynamicManager* m_dynamicManager;
	AnimationParser m_animParser;
	bool m_isDestroyed = false;
};