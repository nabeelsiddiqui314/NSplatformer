#pragma once
#include <SFML/Graphics.hpp>

class Dynamic;

class Animation
{
private:
	struct Frame{
		int x;
		sf::Vector2i size;
	};
	struct AnimationInfo {
		int row, frame, dt;
		bool lateralInversion;
		sf::Vector2f constPoint;
	} m_currentInfo;
	enum State {
		Still,
		PlayingOnce,
		Repeat
	} m_state;
public:
	enum PlayOnceType {
		Normal,
		Reverse,
		Cycle
	} m_playOnceType;
public:
	void setRect(Dynamic* obj);
	void setRowSpacing(int rowSpacing);
	void addRow();
	void AddFrame(const sf::Vector2i& size);
	void setFrame(int row, int frame, bool lateralinversion, const sf::Vector2f& constPoint);
	void repeat(int row, int dt, bool lateralinversion, const sf::Vector2f& constPoint);
	void playOnce(int row, int dt, bool lateralinversion, const sf::Vector2f& constPoint, const PlayOnceType& type = Normal);
	void update();
	bool isPlayingOnce() const;
	const sf::Vector2f& getFrameSize(int row, int column) const;
private:
	void setSingleFrame(int row, int frame, bool lateralinversion, const sf::Vector2f& constPoint);
private:
	Dynamic* m_obj;
	std::vector<std::vector<Frame>> m_rows;
	int m_rowSpacing = 0;
	sf::Clock m_animationClock;
	int m_rowCount = 0;
	int m_widthSum = 0;
	int m_repeatColumn = 0;
	int m_playOnceColumn = 0;
	int m_playOnceIncrement = 1;
};