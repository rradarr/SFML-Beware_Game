#pragma once

#include <memory>
#include <unordered_map>
#include "Scene.h"
#include "Window.h"

/**
*This is an implementation of a FSM for game scenes.
*
*It is used to alter the games behaviour depending on the current
*scene. The scenes are changed during the runtime of the game
*with the use of smart pointers. Each scene holds the ID
*of the sene that is supposed to be activated upon
*deactivation of the current one.
*/
class SceneStateMachine
{
public:
	/// Construct a scene machine.
	SceneStateMachine();
	/// Deconstruct the scene machine.
	~SceneStateMachine();

	/// Call ProcessInput on the current scene.
	void ProcessInput();
	/// Call Update on the current scene.
	void Update(float deltaTime);
	/// Call LateUpdate on the current scene.
	void LateUpdate(float deltaTime);
	/// Call Draw on the current scene.
	void Draw(Window& window);

	/// Check if the scene machine is running.
	bool IsRunning() const;
	/// Stop the scene machine.
	void StopRunning();

	/// Add a new scene to the scene machine.
	unsigned int Add(std::shared_ptr<Scene> scene);
	/// Switch to the next scene.
	void SwithTo(unsigned int id);
	/// Remove a scene.
	void Remove(unsigned int id);

private:
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Scene> curScene;
	unsigned int insertSceneID;
	bool running;
};

