#pragma once

#include <vector>
#include <random>
#include <chrono>

#include "SFML/Graphics.hpp"

/**
*This is an implementation of a graph data structure.
*
*It is used to represent the paths that clients can take.
*It's loaded from a text file. The graph is described
*by an adjacency list.
*/
class Graph
{
public:
	/// Construct the graph.
	Graph();
	/// Deconstruct the graph.
	~Graph();

	/// Initialize the graph with a set amount of verices.
	void InitializeGraph(int _vertices);
	/// Add a vertex described by x and y coordinates.
	void AddVertex(int _id, std::vector<int>& _edges, float _x, float _y);
	/// Get a random vertex ID.
	int GetRandomVertexID();
	/// Operator [] overload.
	sf::Vector2f& operator[] (int _id);
	/// Get the ID of an adjacent vertex whih exclusion of _idAvoid.
	int GetAdjacentVertex(int _idAdjacent, int _idAvoid);

private:
	std::vector<std::vector<int>> adjacencyList;
	std::vector<sf::Vector2f> vertices;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;
};