#include "stdafx.h"
#include "AnimationParser.h"

void AnimationParser::setAnimator(Animation& animator) {
	m_animPtr = &animator;
}

void AnimationParser::parseFile(const std::string& filename) {
	m_filePtr = std::make_unique<std::ifstream>();
	m_filePtr->open(filename + ".txt");
	this->parse();
}

void AnimationParser::parseFile(std::unique_ptr<std::ifstream> file) {
	m_filePtr = std::move(file);
	this->parse();
}

void AnimationParser::parse() {
	std::string temp;
	std::getline(*m_filePtr, temp);
	m_animPtr->setRowSpacing(std::stoi(temp));

	std::string x;
	std::string y;
	std::string* current;

	while (std::getline(*m_filePtr, temp)) {
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