#include "stdafx.h"
#include "EntryPoint.h"
#include "StateManager.h"

StateManager stateManager;

int main()
{
	EntryPoint game;
	game.runloop();
    return 0;
}