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
	if (m_state != PlayingOnce) {
		m_state = Still;
		m_currentInfo = {row, frame, 0, lateralinversion, constPoint};
	}
	
}

void Animation::repeat(int row, int dt, bool lateralinversion, const sf::Vector2f& constPoint) {
	if (m_state != PlayingOnce) {
		m_state = Repeat;
		m_currentInfo = {row, 0, dt, lateralinversion, constPoint};
	}
}

void Animation::playOnce(int row, int dt, bool lateralinversion, const sf::Vector2f& constPoint, bool reverse) {
	if (m_state != PlayingOnce) {
		m_state = PlayingOnce;
		m_currentInfo = {row, 0, dt, lateralinversion, constPoint};
		m_animationClock.restart();
		if (reverse) {
			m_playOnceColumn = m_rows[row].size() - 1;
			m_playOnceIncrement = -1;
		}
		else {
			m_playOnceColumn = 0;
			m_playOnceIncrement = 1;
		}
	}
}

void Animation::update() {
	switch (m_state) {
	case Still:
		this->setSingleFrame(m_currentInfo.row, m_currentInfo.frame, m_currentInfo.lateralInversion, m_currentInfo.constPoint);
		break;
	case PlayingOnce:
		if (m_playOnceColumn > m_rows[m_currentInfo.row].size() - 1 || m_playOnceColumn < 0) {
			m_state = Still;
			break;
		}
		if (m_animationClock.getElapsedTime().asMilliseconds() > m_currentInfo.dt) {
			setSingleFrame(m_currentInfo.row, m_playOnceColumn, m_currentInfo.lateralInversion, m_currentInfo.constPoint);
			m_playOnceColumn += m_playOnceIncrement;
			m_animationClock.restart();
		}
		break;
	case Repeat:
		if (m_repeatColumn > m_rows[m_currentInfo.row].size() - 1) {
			m_repeatColumn = 0;
		}
		if (m_animationClock.getElapsedTime().asMilliseconds() > m_currentInfo.dt) {
			setSingleFrame(m_currentInfo.row, m_repeatColumn, m_currentInfo.lateralInversion, m_currentInfo.constPoint);
			m_repeatColumn++;
			m_animationClock.restart();
		}
		break;
	}
}

void Animation::setSingleFrame(int row, int frame, bool lateralinversion, const sf::Vector2f & constPoint) {
	if (!lateralinversion) {
		m_obj->setTextureRect({ m_rows[row][frame].x,
			m_rowSpacing * row,
			m_rows[row][frame].size.x,
			m_rows[row][frame].size.y },
			constPoint);
	}
	else {
		m_obj->setTextureRect({ m_rows[row][frame].x + m_rows[row][frame].size.x,
			m_rowSpacing * row,
			-m_rows[row][frame].size.x,
			m_rows[row][frame].size.y },
			constPoint);
	}
}