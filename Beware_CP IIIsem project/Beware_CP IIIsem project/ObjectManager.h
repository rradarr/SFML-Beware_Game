#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "SpriteCollection.h"
#include "ColliderCollection.h"
#include "CollectorCollection.h"
#include "ClientCollection.h"
#include "ObjectPlayer.h"
#include "ObjectNotes.h"
#include "Window.h"

/**
*This is an implementation of the object manager.
*
*This class stores and manages all in game entities.
*It provides methods for initializing, editing,
*retrieving and resseting held objects.
*/
class ObjectManager
{
public:
	/// Construct the object manager.
	ObjectManager(Window& _window);
	/// Deconstruct the object manager.
	~ObjectManager();

	/// Reset the game so it can be played again.
	void ResetGame();

	/// Load the textures from files.
	bool LoadTextures();
	/// Load the level from a text file.
	bool LoadLevel();
	/// Initialize the items to be collected across the level.
	void InitItems(int amount);
	/// Initialize the clients across the level.
	bool InitClients(int amount);
	/// Initialize the UI.
	void InitUI();
	/// Initialize the player.
	void InitPlayer();

	/// Get the level sprites.
	SpriteCollection& GetLevel();
	/// Get the UI drawables.
	ObjectNotes& GetUI();
	/// Get the client sprites.
	std::vector<sf::Sprite>& GetClients();
	/// Get the player sprite.
	sf::Sprite& GetPlayer();
	/// Get the colliders drawables. Used for debugging.
	ColliderCollection& GetColliders();
	/// Get the collector drawables.
	CollectorCollection& GetCollectors();
	/// Get the number of infected.
	int GetInfections();
	
	/// Get collider drawable. Used for debugging.
	sf::RectangleShape& GetColliderDrawable();

	/// Move the player by some x and y values.
	void MovePlayer(float xMove, float yMove);
	/// Put on/ take off the player's mask.
	void ChangeMask();
	/// Detect and solve all collisions.
	void SolveCollisions();
	/// Check if the player is collecting any items and collect them.
	bool ChceckCollectors();
	/// Move the clients.
	void MoveClients(float deltaTime);
	/// Evaluate the infections.
	void EvaluateInfections();

private:
	/// Check if the x movement is causing a collision.
	bool xCausesCollision(sf::FloatRect collider);
	/// Check if the y movement is causing the collision.
	bool yCausesCollision(sf::FloatRect collider);

	std::string fileName;
	std::vector<sf::Texture> textures;
	SpriteCollection level;
	ObjectNotes UI;
	ClientCollection clients;
	ObjectPlayer player;
	int shoppingCounter;
	int infected;
	
	ColliderCollection colliders;
	CollectorCollection collectors;

	Window& window;
};

