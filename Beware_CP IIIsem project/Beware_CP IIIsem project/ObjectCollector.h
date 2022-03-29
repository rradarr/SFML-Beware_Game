#pragma once

#include "SFML/Graphics.hpp"

/**
*This is an implementation of an collector object.
*
*A collector object has a collector zone. When a player intersects
*with it and presses E, the item will be collected.
*It also has a rectanlge that can change it's opacity to
*visually signal the presence of an item.
*/
class ObjectCollector
{
public:
	/// Construct a collector.
	ObjectCollector(sf::Sprite& parent, bool _isExit = false);
	/// Deconstruct the collector.
	~ObjectCollector();

	/// Chaeck if the player intersects with the collector zone.
	bool Intersects(sf::RectangleShape playerCollider);
	/// Check if this collector is active.
	bool GetActive();
	/// Get the overlay rectange.
	sf::RectangleShape & GetOverlay();
	/// Check if a collector is an exit.
	bool IsExit();
	/// Activate the collector.
	void ActivateExit();

	/// Get collector for drawing. This method is used for debugging.
	sf::RectangleShape & GetCollector();
	

private:
	sf::RectangleShape collectorZone;
	sf::RectangleShape shelfOverlay;
	bool active;
	bool isExit;
	int counter;
};

