#include "stdafx.h"
#include "AnimationParser.h"

void AnimationParser::setAnimator(Animation& animator) {
	m_animPtr = &animator;
}

void AnimationParser::parseFile(const std::string& filename) {
	m_file.open(filename + ".txt");
	if (!m_file.is_open())
		return;
	std::string temp;
	std::getline(m_file, temp);
	m_animPtr->setRowSpacing(std::stoi(temp));

	std::string x;
	std::string y;
	std::string* current;

	while (std::getline(m_file, temp)) {
		if (temp == "row") {
			m_animPtr->addRow();
		}
		else {
			x.clear();
			y.clear();
			current = &x;

			for (int i = 0; i < temp.size(); i++) {
				if (isdigit(temp[i])) {
					*current += temp[i];
				}
				else {
					current = &y;
				}
			}
			m_animPtr->AddFrame({ std::stoi(x), std::stoi(y) });
		}
	}
}