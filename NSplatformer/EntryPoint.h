#pragma once
#include "Data.h"
#include "Menu.h"
#include "StateManager.h"

class EntryPoint
{
public:
	EntryPoint();
public:
	void runloop();
private:
	sf::RenderWindow m_window;
};