#include "stdafx.h"
#include "Collider.h"

void Collider::Collide(Entity* entity, const int tile, const int row, const int column) {
	sf::Vector2i origin = { column * Data::tileSize, row * Data::tileSize };
	switch (tile) {
	}
}
