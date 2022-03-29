#pragma once

#include "Window.h"

/**
*A virtual class that provides an interface between
*the SceneStateMachine and individual scenes.
*/
class Scene
{
public:

	/// Called at creation of a scene.
	virtual void OnCreate() = 0;
	/// Called on destruction of a scene.
	virtual void OnDestroy() = 0;
	/// Called on activation of a scene.
	virtual void OnActivate() {};
	/// Called on deactivation of a scene.
	virtual void OnDeactivate() {};

	/// Get inputs from the keyboard.
	virtual void ProcessInput() {};
	/// Use inputs to change visuals accordingly.
	virtual void Update(float deltaTime) {};
	/// Carry out a late update of the scene eg. solve collisions.
	virtual void LateUpdate(float deltaTime) {};
	/// Draw a scene to the window.
	virtual void Draw(Window& window) {};
};

