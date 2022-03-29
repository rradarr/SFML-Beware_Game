#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "ObjectClient.h"

/**
*This is an implementation of a client collection.
*
*This class stores clients and provides some methods
*to control them.
*/
class ClientCollection
{
public:
	/// Construct a client collection.
	ClientCollection();
	/// Deconstruct the client collection.
	~ClientCollection();

	/// Clear the collection.
	void Clear();
	/// Read the paths graph from a text file.
	bool ReadGraph(std::string fileName);
	/// Create and distribute a given amount of clients on the map.
	void PopulateLevel(int clientsAmount, const std::vector<sf::Texture>& _textures);
	/// Move all clients and assign target verices.
	void MoveClients(float deltaTime);
	/// Check if any clients got infected this frame.
	bool EvaluateInfections(sf::Vector2f playerPos, bool _mask);
	/// Get the client's sprites.
	std::vector<sf::Sprite>& GetCollection();

private:
	Graph paths;
	std::vector<ObjectClient> clients;
	std::vector<sf::Sprite> clientSprites;

	std::uniform_int_distribution<int> distribution;
	unsigned int seed;
	std::default_random_engine generator;
};

