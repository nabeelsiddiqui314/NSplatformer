#include "stdafx.h"
#include "Animation.h"

void Animation::setRect(sf::RectangleShape* rect) {
	m_rect = rect;
}

void Animation::setSize(const sf::Vector2i& size) {
	m_size = size;
}

void Animation::setFrame(int row, int frame) {
	m_rect->setTextureRect({ m_size.x * row, m_size.y * frame, m_size.x, m_size.y });
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