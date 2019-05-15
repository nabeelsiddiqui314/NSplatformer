#include "stdafx.h"
#include "Dynamic.h"
#include "DynamicManager.h"

Dynamic::Dynamic() {
	p_animation.setRect(this);
}

void Dynamic::setPos(const sf::Vector2f& pos) {
	m_body.setPosition(pos);
}

void Dynamic::setPos(float x, float y) {
	m_body.setPosition(x, y);
}

void Dynamic::move(const sf::Vector2f& dp) {
	m_body.move(dp);
}

const sf::Vector2f& Dynamic::getPos() const {
	return m_body.getPosition();
}

const sf::Vector2f Dynamic::getSize() const {
	return { m_body.getGlobalBounds().width, m_body.getGlobalBounds().height};
}

void Dynamic::setTextureRect(const sf::IntRect& rect, const sf::Vector2f& constPoint) {
	sf::Vector2f oldSize = this->getSize();
	m_body.setTextureRect(rect);
	sf::Vector2f newConstPoint = {constPoint.x / oldSize.x * this->getSize().x,
		                          constPoint.y / oldSize.y * this->getSize().y };
	m_body.move(constPoint.x - newConstPoint.x, constPoint.y - newConstPoint.y);
}

void Dynamic::setDynamicManager(DynamicManager* dm) {
	m_dynamicManager = dm;
}

void Dynamic::addObject(Dynamic* newObj, const sf::Vector2f& pos) {
	m_dynamicManager->addObject(newObj, pos);
}

bool Dynamic::isDestroyed() const {
	return m_isDestroyed;
}

void Dynamic::render(sf::RenderWindow& window) {
	window.draw(m_body);
}

void Dynamic::setTexture(const std::string& name) {
	m_body.setTexture(Resources::textures.get(name));
}

bool Dynamic::isCollidingOther(const Dynamic* other) const {
	return sf::FloatRect(this->getPos(), this->getSize()).intersects({ other->getPos(), other->getSize() });
}

void Dynamic::destroy() {
	m_isDestroyed = true;
}