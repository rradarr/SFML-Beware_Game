#pragma once

#include "SFML/Graphics.hpp"

/**
*This class implements a collection of colliders.
*/
class ColliderCollection
{
public:
	/// Construct a collection of colliders.
	ColliderCollection();
	/// Deconstruct the collection of colliders.
	~ColliderCollection();

	/// Add a new collider to the collection.
	void AddCollider(sf::Sprite& parent, int type);
	/// Get the collection.
	std::vector<sf::RectangleShape>& GetCollection();

	/// Operator [] overload.
	sf::RectangleShape& operator[](unsigned int id);

private:
	std::vector<sf::RectangleShape> collection;
};

