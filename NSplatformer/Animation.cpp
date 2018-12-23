#include "stdafx.h"
#include "Animation.h"

void Animation::init(sf::RectangleShape* rect, const sf::Vector2i& size, const sf::Vector2i& defaultFrame) {
	m_rect = rect;
	m_size = size;
	m_rect->setTextureRect({m_size.x * defaultFrame.x, m_size.y * defaultFrame.y, m_size.x, m_size.y });
}

void Animation::animate(int row, int frames, int dt) {
	if (m_column > frames - 1) {
		m_column = 0;
	}
	if (m_animationClock.getElapsedTime().asMilliseconds() > dt) {
		m_rect->setTextureRect({m_size.x * m_column, m_size.y * row, m_size.x, m_size.y });
		m_column++;
		m_animationClock.restart();
	}
}