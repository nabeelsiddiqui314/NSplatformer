#include "stdafx.h"
#include "ParallaxBG.h"


void ParallaxBG::init(const std::string& folder, bool isFixedY) {
	m_isYfixed = isFixedY;

	int i = 0;
	bool end = false;
	while (!end) {
		if (Resources::textures.doesExist(folder + "/" + std::to_string(i + 1))) {
			sf::Sprite s;
			s.setTexture(Resources::textures.get(folder + "/" + std::to_string(i + 1)));
			m_backgrounds[0].push_back(s);
			m_backgrounds[1].push_back(s);
			m_backgrounds[0][i].setPosition(0, 0);
			m_backgrounds[1][i].setPosition( m_backgrounds[0][i].getPosition().x + m_backgrounds[0][i].getGlobalBounds().width,
											  m_backgrounds[0][i].getPosition().y );
			i++;
		}
		else
			end = true;
	}
}

void ParallaxBG::update(const sf::Vector2f& playerPos, float xVelocity) {
	if (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m_backgrounds[0].size(); j++) {
				m_backgrounds[0][j].move(xVelocity / (j + 1), 0);
				m_backgrounds[1][j].move(xVelocity / (j + 1), 0);
				if (m_isYfixed) {
					m_backgrounds[i][j].setPosition(m_backgrounds[i][j].getPosition().x, playerPos.y - m_backgrounds[i][j].getGlobalBounds().height / 2);
				}
				if (playerPos.x > m_backgrounds[i][j].getPosition().x + m_backgrounds[i][j].getGlobalBounds().width / 2 &&
					playerPos.x > m_backgrounds[swap(i)][j].getPosition().x + m_backgrounds[swap(i)][j].getGlobalBounds().width / 2) {
					if (m_backgrounds[i][j].getPosition().x > m_backgrounds[swap(i)][j].getPosition().x) {
						m_backgrounds[swap(i)][j].setPosition( m_backgrounds[i][j].getPosition().x + m_backgrounds[i][j].getGlobalBounds().width,
																m_backgrounds[swap(i)][j].getPosition().y );
					}
				}
				if (playerPos.x < m_backgrounds[i][j].getPosition().x + m_backgrounds[i][j].getGlobalBounds().width / 2 &&
					playerPos.x < m_backgrounds[swap(i)][j].getPosition().x + m_backgrounds[swap(i)][j].getGlobalBounds().width / 2) {
					if (m_backgrounds[i][j].getPosition().x < m_backgrounds[swap(i)][j].getPosition().x) {
						m_backgrounds[swap(i)][j].setPosition( m_backgrounds[i][j].getPosition().x - m_backgrounds[i][j].getGlobalBounds().width,
																m_backgrounds[swap(i)][j].getPosition().y );
					}
				}
			}
		}
	}
}

void ParallaxBG::render(sf::RenderWindow& window) {
	for (int i = 0; i < m_backgrounds[0].size(); i++) {
		window.draw(m_backgrounds[0][i]);
		window.draw(m_backgrounds[1][i]);
	}
}

int ParallaxBG::swap(int num) {
	if (num == 0)
		return 1;
	else if(num == 1)
		return 0;
}