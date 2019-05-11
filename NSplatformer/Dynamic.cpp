#include "stdafx.h"
#include "Dynamic.h"

Dynamic::Dynamic() {
	p_animation.setRect(&m_body);
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

void Dynamic::render(sf::RenderWindow& window) {
	window.draw(m_body);
}

void Dynamic::setTexture(const std::string& name) {
	m_body.setTexture(Resources::textures.get(name));
}

bool Dynamic::isCollidingOther(const Dynamic* other) const {
	return sf::FloatRect(this->getPos(), this->getSize()).intersects({ other->getPos(), other->getSize() });
}
