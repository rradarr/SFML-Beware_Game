#include "Graph.h"

#include <iostream>

Graph::Graph()
{
}

Graph::~Graph()
{
	for (auto& elem : adjacencyList)
		elem.clear();

	vertices.clear();
}

void Graph::InitializeGraph(int _vertices)
{
	for (int i = 0; i < _vertices; i++)
	{
		adjacencyList.push_back(std::vector<int>(_vertices, 0));
		vertices.push_back(sf::Vector2f(0, 0));
	}
	distribution = std::uniform_int_distribution<int>(0, _vertices - 1);
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator = std::default_random_engine(seed);
}

void Graph::AddVertex(int _id, std::vector<int>& _edges, float _x, float _y)
{
	for (int edge : _edges)
	{
		adjacencyList[_id][edge] = 1;
		adjacencyList[edge][_id] = 1;
	}
	vertices[_id] = sf::Vector2f(_x, _y);

	//debug
	/*
	for (auto tab : adjacencyList)
	{
		for (auto tab2 : tab)
		{
			std::cout << tab2 << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
}

int Graph::GetRandomVertexID()
{
	
	int vertex = distribution(generator);
	return vertex;
}

sf::Vector2f & Graph::operator[](int _id)
{
	return vertices[_id];
}

int Graph::GetAdjacentVertex(int _idAdjacent, int _idAvoid)
{
	std::vector<int> adjacentVertecies;
	for (int i = 0; i < adjacencyList[_idAdjacent].size(); i++)
	{
		if(adjacencyList[_idAdjacent][i] != 0 && i != _idAvoid)
			adjacentVertecies.push_back(i);
	}
	for (auto i : adjacentVertecies)
	{
		//std::cout << i << " ";
	}
	//std::cout << std::endl;
	std::uniform_int_distribution<int> tmpDistribution(0, adjacentVertecies.size() - 1);
	return adjacentVertecies[tmpDistribution(generator)];
}
