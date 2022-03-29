#include "ObjectClient.h"

#include <iostream>

ObjectClient::ObjectClient() : vertexToID(-1),vertexFromID(-1), speed(50), infected(false)
{
	sprite = nullptr;
}

ObjectClient::~ObjectClient()
{
	sprite = nullptr;
}

void ObjectClient::operator=(const ObjectClient & _client)
{
	sprite = _client.sprite;
	vertexToID = _client.vertexToID;
	vertexFromID = _client.vertexFromID;
	speed = _client.speed;
}

void ObjectClient::AppendSprite(sf::Sprite& _sprite)
{
	sprite = &_sprite;
}

void ObjectClient::SetTargetVertex(int _id)
{
	vertexToID = _id;
	vertexFromID = _id;
}

void ObjectClient::SetSpeed(float _speed)
{
	speed = _speed;
}

void ObjectClient::MoveClient(Graph& graph, float deltaTime)
{
	if (!isCloseEnough(graph[vertexToID]))
	{
		sf::Vector2f vertexTo = graph[vertexToID];
		sf::Vector2f pos = sprite->getPosition();
		sf::Vector2f direction = vertexTo - pos;
		sf::Vector2f normalized = direction / (sqrt(direction.x * direction.x + direction.y * direction.y));
		sprite->setPosition(pos + normalized * speed * deltaTime);
	}
	else
	{
		//std::cout << "At: " << vertexToID << " " << std::endl;
		int tmpTo = vertexToID;
		vertexToID = graph.GetAdjacentVertex(vertexToID, vertexFromID);
		vertexFromID = tmpTo;
		//std::cout << "Picking new vertex: " << vertexToID << std::endl;
	}
}

sf::Vector2f ObjectClient::GetPosition()
{
	return sprite->getPosition();
}

void ObjectClient::SetInfected()
{
	infected = true;
}

bool ObjectClient::GetInfected()
{
	return infected;
}

bool ObjectClient::isCloseEnough(sf::Vector2f vertex)
{
	sf::Vector2f pos = sprite->getPosition();
	int margin = 5;
	if (pos.x > vertex.x - margin && pos.x < vertex.x + margin &&
		pos.y > vertex.y - margin && pos.y < vertex.y + margin)
	{
		return true;
	}
	return false;
}
