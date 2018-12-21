#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>

template<typename Resource>
class ResourceLoader
{
public:
	void init(const std::string& folder, const std::string& extention) {
		m_folder = "./resources/" + folder + "/";
		m_extention = "." + extention;
		m_fail.loadFromFile(getFilename("fail"));
	}

	void add(const std::string& filepath, const std::string& name) {
		Resource r;
		if (r.loadFromFile(getFilename(filepath))) {
			m_resources.insert(std::make_pair(name, r));
		}
	}

	void add(const std::string& name) {
		Resource r;
		if (r.loadFromFile(getFilename(name))) {
			m_resources.insert(std::make_pair(name, r));
		}
	}

	Resource& get(const std::string& name) {
		if (m_resources.find(name) == m_resources.end())
			return m_fail;
		else
			return m_resources.at(name);
	}
private:
	const std::string getFilename(const std::string& name) {
		return (m_folder + name + m_extention);
	}
private:
	std::unordered_map<std::string, Resource> m_resources;

	std::string m_folder;
	std::string m_extention;
	std::string m_filepath;
	Resource m_fail;
};