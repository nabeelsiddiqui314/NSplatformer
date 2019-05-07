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
	soundBuffers.add("guiselect");

	textures.add("player");
	//temp
	textures.add("testTileset");
	textures.add("Forest/1");
	textures.add("Forest/2");
	textures.add("Forest/3");
	textures.add("Forest/4");
	textures.add("Forest/5");
	textures.add("Forest/6");
	textures.add("Forest/7");
	textures.add("Forest/8");
	textures.add("Forest/9");
	textures.add("Forest/10");
	textures.add("Forest/11");
}

