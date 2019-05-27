#include "stdafx.h"
#include "ObjectDataParser.h"


ObjectDataParser::ObjectDataParser(const std::string& name) {
	m_dataFile.open("data/objects/" + name + ".txt");

	std::string temp;
	while (std::getline(m_dataFile, temp)) {
		std::string varName;
		std::string varVal;
		
		std::size_t colonPos= temp.find(":");
		varName = temp.substr(0, colonPos);
		varVal = temp.substr(colonPos + 1);
		m_vars.insert(std::make_pair(varName, varVal));
	}
}

const std::string& ObjectDataParser::getValue(const std::string& varName) const {
	return m_vars.at(varName);
}

ObjectDataParser::~ObjectDataParser() {
	m_dataFile.close();
}