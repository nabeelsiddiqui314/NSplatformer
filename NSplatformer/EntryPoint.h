#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"

class EntryPoint
{
public:
	EntryPoint();
public:
	void runloop();
private:
	sf::RenderWindow m_window;
	sf::Clock        m_clock;
	sf::Time         m_accumulator = sf::Time::Zero;
	sf::Time         m_ups = sf::seconds(1.f / 60.f);
};