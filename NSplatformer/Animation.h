#pragma once
#include <SFML/Graphics.hpp>

class Dynamic;

class Animation
{
private:
	struct Frame{
		int x;
		sf::Vector2i size;
	};
public:
	void setRect(Dynamic* obj);
	void setRowSpacing(int rowSpacing);
	void addRow();
	void AddFrame(const sf::Vector2i& size);
	void setFrame(int row, int frame, bool lateralinversion, const sf::Vector2f& constPoint);
	void animate(int row, int dt, bool lateralinversion, const sf::Vector2f& constPoint);
private:
	Dynamic* m_obj;
	std::vector<std::vector<Frame>> m_rows;
	std::vector<int> m_xValues;
	int m_rowSpacing = 0;
	sf::Clock m_animationClock;
	int m_rowCount = 0;
	int m_animColumn = 0;
	int m_widthSum = 0;
};

