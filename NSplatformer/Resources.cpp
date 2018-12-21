#include "stdafx.h"
#include "Resources.h"

ResourceLoader<sf::Texture>     Resources::textures;
ResourceLoader<sf::Font>        Resources::fonts;
ResourceLoader<sf::SoundBuffer> Resources::soundBuffers;

void Resources::init() {
	textures.init("graphics", "png");
	fonts.init("fonts", "ttf");
	soundBuffers.init("audio", "wav");

	fonts.add("thinPix", "8bitfont");
}

