#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

/**
*This is an implementation of a collection of sprites.
*
*This class holds a group of sprites and provides methods
*to add sprites and retrieve them.
*/
class SpriteCollection
{
public:
	/// Construct a new collection.
	SpriteCollection();
	/// Deconstruct the collection.
	~SpriteCollection();
	
	/// Add a new sprite to the collection.
	void AddSprite(sf::Texture& texture, float x = 0, float y = 0, float scaleX = 1, float scaleY = 1, float rotation = 0);
	/// Get the collection of sprites.
	std::vector<sf::Sprite>& GetCollection();

	/// Operator [] overload.
	sf::Sprite& operator[](unsigned int id);

private:
	std::vector<sf::Sprite> collection;
};

