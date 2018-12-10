#pragma once
#include <SFML/Graphics.hpp>

class Gui_obj
{
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;

	virtual void update(const sf::RenderWindow& window) {}
	void render(sf::RenderWindow& window);
protected:
	void init();
	void setString(const std::string& string);
	void setColor(const sf::Color& color);
	bool isHovered(const sf::RenderWindow& window);
private:
	sf::Text m_text;
};

