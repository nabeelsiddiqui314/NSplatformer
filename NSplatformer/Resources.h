#pragma once
#include "ResourceLoader.h"


class Resources
{
	Resources() = delete;
public:
	static void init();
	static ResourceLoader<sf::Texture>     textures;
	static ResourceLoader<sf::Font>        fonts;
	static ResourceLoader<sf::SoundBuffer> soundBuffers;
};