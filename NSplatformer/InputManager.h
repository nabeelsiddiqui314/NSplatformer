#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
	InputManager() = delete;
public:
	enum Button {
		Enter = 0,
		MouseLeft,
		MouseRight,
		ArrowUp,
		ArrowDown,
		ArrowLeft,
		ArrowRight,
		W,
		Ctrl
	};
public:
	static void init();
	static void getInput();
	static void updateOldInput();
	static bool isClicked(const Button& button);
	static bool isReleased(const Button& button);
private:
	static void detectCurrentInput(const Button&, bool condition);
	static void updateInputFor(const Button& button);
private:
	static std::vector<bool> s_oldInput;
	static std::vector<bool> s_currentInput;
};

