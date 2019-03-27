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

void GameView::moveCamera(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Vector2f& deltaPos) {
	float x, y;
	bool left = false, right = false, top = false, bottom = false;
	if (pos.x - deltaPos.x + size.x/2 <= m_camSize.x/2) {
		left = true;
		x = 0;
		
	}
	else if (m_camSize.x/2 + pos.x + deltaPos.x - size.x/2 >= m_worldSize.x) {
		right = true;
		x = 0;
		
	}
	else {
		x = deltaPos.x;
	}

	if (pos.y - deltaPos.y + size.x/2 <= m_camSize.y/2) {
		top = true;
		y = 0;
		
	}
	else if(m_camSize.y/2 + pos.y + deltaPos.y - size.y/2 >= m_worldSize.y) {
		bottom = true;
		y = 0;
	}
	else {
		y = deltaPos.y;
	}
	m_view.move({x, y});

	 if(left)
		 m_view.setCenter(m_camSize.x / 2, m_view.getCenter().y);
	 if(right)
		 m_view.setCenter(m_worldSize.x - m_camSize.x / 2, m_view.getCenter().y);
	 if(top)
		 m_view.setCenter(m_view.getCenter().x, m_camSize.y / 2);
	 if(bottom)
		 m_view.setCenter(m_view.getCenter().x, m_worldSize.y - m_camSize.y / 2);
}

const sf::View& GameView::getView() const {
	return m_view;
}

bool GameView::isInView(const sf::Vector2f& pos, const sf::Vector2f& size) const {
	return sf::FloatRect( {m_view.getCenter().x - m_view.getSize().x / 2, m_view.getCenter().y - m_view.getSize().y / 2 }, 
		                   m_view.getSize()).intersects({ pos, size });
}
