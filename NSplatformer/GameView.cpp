#include "stdafx.h"
#include "GameView.h"

void GameView::setSize(const sf::Vector2f& size) {
	m_size = size;
	m_view.setSize(size);
	m_view.setCenter({Data::windowWidth / 2, Data::windowHeight/2});
}

void GameView::setWorldSize(const sf::Vector2f& size) {
	m_worldSize = size;
}

void GameView::moveCamera(const sf::Vector2f& deltaPos) {
	float x, y;
	if (deltaPos.x + m_size.x / 2 <= 0 || m_worldSize.x - deltaPos.x - m_size.x / 2 <= 0) {
		x = m_view.getCenter().x;
	}
	else {
		x = deltaPos.x;
	}

	if (deltaPos.x + m_size.x / 2 <= 0 || m_worldSize.x - deltaPos.x - m_size.x / 2 <= 0) {
		y = m_view.getCenter().y;
	}
	else {
		y = deltaPos.y;
	}
	m_view.move({x, y});
}

void GameView::setView(sf::RenderWindow& window) {
	window.setView(m_view);
}

bool GameView::isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const {
	return m_view.getViewport().intersects({pos, size});
}
