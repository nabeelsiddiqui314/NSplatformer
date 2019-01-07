#include "stdafx.h"
#include "GameView.h"

void GameView::setPos(const sf::Vector2f& pos) {
	m_view.setCenter(pos);
}

void GameView::setSize(const sf::Vector2f& size) {
	m_size = size;
	m_view.setSize(size);
}

void GameView::setWorldSize(const sf::Vector2f& size) {
	m_worldSize = size;
}

void GameView::moveCamera(const sf::Vector2f& pos, const sf::Vector2f& deltaPos) {
	float x, y;
	bool left = false, right = false, top = false, bottom = false;
	if (pos.x - deltaPos.x - m_size.x / 2 <= 0) {
		left = true;
		x = 0;
		
	}
	else if (m_worldSize.x - pos.x - deltaPos.x - m_size.x / 2 <= 0) {
		right = true;
		x = 0;
		
	}
	else {
		x = deltaPos.x;
	}

	if (pos.y - deltaPos.y - m_size.y / 2 <= 0) {
		top = true;
		y = 0;
		
	}
	else if(m_worldSize.y - pos.y - deltaPos.y - m_size.y / 2 <= 0) {
		bottom = true;
		y = 0;
		
	}
	else {
		y = deltaPos.y;
	}
	m_view.move({x, y});

	 if(left)
		 m_view.setCenter(m_size.x / 2, m_view.getCenter().y);
	 if(right)
		 m_view.setCenter(m_worldSize.x - m_size.x / 2, m_view.getCenter().y);
	 if(top)
		 m_view.setCenter(m_view.getCenter().x, m_size.y / 2);
	 if(bottom)
		 m_view.setCenter(m_view.getCenter().x, m_worldSize.y - m_size.y / 2);
}

void GameView::setView(sf::RenderWindow& window) {
	window.setView(m_view);
}

bool GameView::isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const {
	return m_view.getViewport().intersects({pos, size});
}
