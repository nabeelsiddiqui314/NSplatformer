#pragma once
#include "Resources.h"
#include "Data.h"

class Gui_obj
{
public:
	void setPos(const sf::Vector2f& pos);
	const float height() const;
	const float bottomPos() const;
	const sf::Vector2f& getPos() const;

	void select();
	void deselect();

	bool isHovering(const sf::RenderWindow& window);

	virtual void update(const sf::RenderWindow& window) {}
	virtual void render(sf::RenderWindow& window);

	virtual ~Gui_obj() {}
protected:
	void init();
	void setString(const std::string& string);
	void setColor(const sf::Color& color);
	bool isSelected();
protected:
	sf::Sound m_interactSound;
private:
	sf::Text m_text;
	sf::Sound m_selectSound;
	bool m_selected = false;
	bool m_selectedLastFrame = false;
};

