#pragma once
#include <SFML/Graphics.hpp>

class Gui_obj
{
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;

	void select();
	void deselect();

	bool isHovering(const sf::RenderWindow& window);

	virtual void update() {}
	virtual void render(sf::RenderWindow& window);

	virtual ~Gui_obj() {}
protected:
	void init();
	void setString(const std::string& string);
	void setColor(const sf::Color& color);
	bool isSelected();
private:
	sf::Text m_text;
	bool m_selected = false;
};

