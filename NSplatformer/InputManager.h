#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
public:
	enum Button {
		Enter = 0,
		MouseLeft,
		MouseRight,
		ArrowUp,
		ArrowDown,
		ArrowLeft,
		ArrowRight
	};
private:
	InputManager();
public:
	static void getCurrentInput();
	static void getOldInput();
	static bool isPressed(Button button);
private:
	static void currentInputHandler(Button, bool condition);
	static void oldInputHandler(Button button, bool condition);
private:
	static std::vector<bool> s_oldInput;
	static std::vector<bool> s_currentInput;
};

