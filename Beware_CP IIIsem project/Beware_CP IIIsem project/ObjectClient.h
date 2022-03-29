#pragma once

#include "Graph.h"

/**
*This is an implementation of a client.
*
*It contains the sprite of a client and
*methods to move the client using the Graph.
*It also stores data about infections.
*/
class ObjectClient
{
public:
	/// Construct a client.
	ObjectClient();
	/// Deconstruct the client.
	~ObjectClient();

	/// Operator = overload.
	void operator = (const ObjectClient& _client);

	/// Set the sprite pointer of the client to a sprite.
	void AppendSprite(sf::Sprite& _sprite);
	/// Set the vertex to which the client will move.
	void SetTargetVertex(int _id);
	/// Set the speed of the client.
	void SetSpeed(float _speed);

	/// Move the client towards target vertex.
	void MoveClient(Graph& graph, float deltaTime);
	/// Get the position of the client.
	sf::Vector2f GetPosition();
	/// Set the client as infected.
	void SetInfected();
	/// Check if this client is infected.
	bool GetInfected();

private:
	/// Check if the client is close enough to a vertex based on a set margin.
	bool isCloseEnough(sf::Vector2f vertex);

	sf::Sprite* sprite;
	int vertexToID, vertexFromID;
	float speed;
	bool infected;
};

