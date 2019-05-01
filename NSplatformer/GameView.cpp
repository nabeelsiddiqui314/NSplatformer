#include "stdafx.h"
#include "GameView.h"

void GameView::setPos(const sf::Vector2f& pos) {
	m_view.setCenter(pos);
}

void GameView::setSize(const sf::Vector2f& size) {
	m_camSize = size;
	m_view.setSize(size);
}

void GameView::setWorldSize(const sf::Vector2i& size) {
	m_worldSize = size;
}

void GameView::setFocus(const xDirection & dir) {
	m_playerDir = dir;
}

void GameView::moveCamera(const sf::Vector2f& playerPos, bool isJumping) {
	float dx = 0, dy = 0;
	if (m_playerDir == xDirection::LEFT) {
		dx = (playerPos.x - m_view.getCenter().x - Data::camera::foresight) / Data::camera::smoothness;
	}
	else if (m_playerDir == xDirection::RIGHT) {
		dx = (playerPos.x - m_view.getCenter().x + Data::camera::foresight) / Data::camera::smoothness;
	}
	if (!isJumping) {
		dy = (playerPos.y - m_view.getCenter().y) / Data::camera::smoothness;
	}
	else {
		dy = 0;
	}
	m_view.setCenter(dx + m_view.getCenter().x, dy + m_view.getCenter().y);

}

const sf::View& GameView::getView() const {
	return m_view;
}

bool GameView::isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const {
	return sf::FloatRect( {m_view.getCenter().x - m_view.getSize().x / 2, m_view.getCenter().y - m_view.getSize().y / 2 }, 
		                   m_view.getSize()).intersects({ pos, size });
}
