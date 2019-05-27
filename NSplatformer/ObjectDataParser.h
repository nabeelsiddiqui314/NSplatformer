#pragma once
#include <fstream>
#include <string>
#include <unordered_map>

class ObjectDataParser
{
public:
	ObjectDataParser(const std::string& name);
	~ObjectDataParser();
public:
	const std::string& getValue(const std::string& varName) const;
private:
	std::ifstream m_dataFile;
	std::unordered_map<std::string, std::string> m_vars;
};