#pragma once
#include <fstream>
#include <memory>
#include "Animation.h"

class AnimationParser
{
public:
	void setAnimator(Animation& animator);
	void parseFile(const std::string& filename);
	void parseFile(std::unique_ptr<std::ifstream> file);
private:
	void parse();
private:
	Animation* m_animPtr;
	std::unique_ptr<std::ifstream> m_filePtr;
};