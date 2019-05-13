#include "stdafx.h"
#include "Animation.h"
#include "Dynamic.h"

void Animation::setRect(Dynamic* obj) {
	m_obj = obj;
	m_rows.emplace_back();
}

void Animation::setRowSpacing(int rowSpacing) {
	m_rowSpacing = rowSpacing;
}

void Animation::addRow() {
	m_rowCount++;
	m_widthSum = 0;
	m_rows.emplace_back();
}

void Animation::AddFrame(const sf::Vector2i& size) {
	m_rows[m_rowCount].push_back({ m_widthSum, size });
	m_widthSum += size.x;
}

void Animation::setFrame(int row, int frame, bool lateralinversion, const sf::Vector2f& constPoint) {
	if (!lateralinversion) {
		m_obj->setTextureRect({ m_rows[row][frame].x, 
			                    m_rowSpacing * row,
			                    m_rows[row][frame].size.x, 
			                    m_rows[row][frame].size.y}, 
			                    constPoint);
	}
	else {
		m_obj->setTextureRect({ m_rows[row][frame].x + m_rows[row][frame].size.x, 
			                    m_rowSpacing * row,
			                   -m_rows[row][frame].size.x,
			                    m_rows[row][frame].size.y},
			                    constPoint);
	}
}

void Animation::animate(int row, int dt, bool lateralinversion, const sf::Vector2f& constPoint) {
	if (m_animColumn > m_rows[row].size() - 1) {
		m_animColumn = 0;
	}
	if (m_animationClock.getElapsedTime().asMilliseconds() > dt) {
		setFrame(row, m_animColumn, lateralinversion, constPoint);
		m_animColumn++;
		m_animationClock.restart();
	}
}

