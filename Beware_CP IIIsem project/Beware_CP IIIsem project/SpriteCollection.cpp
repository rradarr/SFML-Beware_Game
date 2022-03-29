#include "SpriteCollection.h"

SpriteCollection::SpriteCollection()
{
}

SpriteCollection::~SpriteCollection()
{
	collection.clear();
}

void SpriteCollection::AddSprite(sf::Texture& texture, float x, float y, float scaleX, float scaleY, float rotation)
{
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setScale(scaleX, scaleY);
	sprite.setRotation(rotation);

	collection.push_back(sprite);
}

std::vector<sf::Sprite>& SpriteCollection::GetCollection()
{
	return collection;
}

sf::Sprite & SpriteCollection::operator[](unsigned int id)
{
	return collection[id];
}
