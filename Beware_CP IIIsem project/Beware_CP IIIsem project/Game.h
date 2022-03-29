#pragma once

#include "Window.h"
#include "ObjectManager.h"
#include "SceneStateMachine.h"
#include "SceneMenu.h"
#include "SceneMenuPause.h"
#include "SceneMenuStats.h"
#include "SceneGame.h"

/**
*This is an implementation of the game.
*
*It is the most general class and all other classes are
*directly or indirectly used by it.
*/
class Game
{
public:
	/// Construct the game.
	Game();
	/// Deconstruct the game.
	~Game();

	/// Get keyboard inputs.
	void ProcessInput();
	/// Update the game based on the inputs.
	void Update();
	/// Uptade the game's internall mechanics.
	void LateUpdate();
	/// Draw the game to a window.
	void Draw();
	/// Check if the game is running.
	bool IsRunning() const;
	/// Get the time between frames.
	void GetDeltaTime();

private:
	Window window;
	ObjectManager objManager;
	sf::Clock clock;
	float deltaTime;

	SceneStateMachine sceneStateMachine;
};

