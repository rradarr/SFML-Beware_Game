#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "Input.h"
#include "SceneStateMachine.h"
#include "Window.h"

/**
*This is an implementation of the main menu scene.
*
*It inherits from the Sene class which provides a
*general interface between the scenes and the SceneStateMachine.
*/
class SceneMenu : public Scene
{
public:
	/// Construct a menu scene.
	SceneMenu(Window& _window, SceneStateMachine& _sceneMachine);
	/// Deconstruct the menu scene.
	~SceneMenu();

	/// Set up the text and buttons of the menu.
	void OnCreate() override;
	/// Placeholder.
	void OnDestroy() override;

	/// Set the scene that will be acivated after this scene.
	void SetNextScene(unsigned int _id);
	/// Get the keyboard inputs.
	void ProcessInput() override;
	/// Update visuals according to the input.
	void Update(float deltaTime) override;
	/// Draw the scene to the screen.
	void Draw(Window& window) override;

protected:
	Window& window;
	SceneStateMachine& sceneMachine;
	unsigned int nextScene;
	Input input;

	sf::Font font;
	int positionID; ///< The ID of the active selected menu element.
	std::vector<std::pair<sf::RectangleShape, sf::Text>> selectableMenuElements;

};

