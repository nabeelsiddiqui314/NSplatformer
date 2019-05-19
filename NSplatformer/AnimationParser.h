#pragma once
#include <fstream>
#include <memory>
#include "Animation.h"

class AnimationParser
{
public:
	void setAnimator(Animation& animator);
	void parseFile(const std::string& filename);
private:
	Animation* m_animPtr;
	std::ifstream m_file;
};