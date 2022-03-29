#pragma once

#include <iostream>
#include <tuple>

#include "Scene.h"
#include "Input.h"
#include "SceneStateMachine.h"
#include "ObjectManager.h"

/**
*This is an implementation of the game scene.
*
*In this scene the game takes place. Operations like loading the game,
*moving the player character, evaluation of the infections etc.
*happen in this class.
*/
class SceneGame: public Scene
{
public:
	/// Construct a game scene.
	SceneGame(Window& _window, SceneStateMachine& _sceneMachine, ObjectManager& _objManager);
	/// Deconstruct the game scene.
	~SceneGame();

	/// Setup the scene.
	void OnCreate() override;
	/// Placeholder.
	void OnDestroy() override;
	/// Placeholder.
	void OnDeactivate() override;

	/// Set the next scene.
	void SetNextScene(unsigned int _id);
	/// Set the pause menu scene.
	void SetPauseScene(unsigned int _id);
	/// Get the keyboard inputs.
	void ProcessInput() override;
	/// Update visuals according to the input.
	void Update(float deltaTime) override;
	/// Solve collisions, evaluate infections and move the camera.
	void LateUpdate(float deltaTime) override;
	/// Draw the scene to the window.
	void Draw(Window& window) override;

private:
	Window& window;
	ObjectManager& objManager;
	SceneStateMachine& sceneMachine;
	Input input;
	unsigned int nextScene;
	unsigned int pauseScene;
};

