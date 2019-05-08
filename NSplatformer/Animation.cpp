#include "stdafx.h"
#include "Animation.h"

void Animation::setRect(sf::Sprite* rect) {
	m_rect = rect;
}

void Animation::setSize(const sf::Vector2i& size) {
	m_size = size;
}

void Animation::setSpacing(const sf::Vector2i& spacing) {
	m_spacing = spacing;
}

void Animation::setFrame(int row, int frame, bool lateralinversion) {
	if (!lateralinversion) {
		m_rect->setTextureRect({ m_size.x * frame + frame * m_spacing.x, m_size.y * row + row * m_spacing.y,
								 m_size.x, m_size.y });
	}
	else {
		m_rect->setTextureRect({ m_size.x + m_size.x * frame + frame * m_spacing.x, m_size.y * row + row * m_spacing.y,
			-m_size.x, m_size.y });
	}
}

void Animation::animate(int row, int frames, int dt, bool lateralinversion) {
	if (m_column > frames - 1) {
		m_column = 0;
	}
	if (m_animationClock.getElapsedTime().asMilliseconds() > dt) {
		setFrame(row, m_column, lateralinversion);
		m_column++;
		m_animationClock.restart();
	}
}

