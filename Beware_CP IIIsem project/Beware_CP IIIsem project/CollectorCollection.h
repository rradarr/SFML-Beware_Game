#pragma once

#include "ObjectPlayer.h"
#include "ObjectCollector.h"

/**
*This is an implementation of a collector collection.
*/
class CollectorCollection
{
public:
	/// Construct the collector collection.
	CollectorCollection();
	/// Deconstruct the collector collection.
	~CollectorCollection();

	/// Clear this collector collection.
	void Clear();
	/// Add a collector to this collection.
	void AddCollector(sf::Sprite& parent);
	/// Add an exit collector to this collection.
	void AddExit(sf::Sprite& parent);
	/// Activate exits.
	void ActivateExit();
	/// Check if the player is intersecting with any active collectors.
	bool CheckCollectors(ObjectPlayer& player);
	/// Get this collection.
	std::vector<ObjectCollector>& GetCollection();

private:
	std::vector<ObjectCollector> collectors;
};

