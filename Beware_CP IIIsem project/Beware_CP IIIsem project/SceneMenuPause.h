#pragma once

#include "SceneMenu.h"
#include "SceneGame.h"

/**
*This is an implementation of the pasue menu screen.
*
*It inherits from SceneMenu and overrides it's OnCreate()
*and Draw() methods to achieve a different visual composition.
*It holds a reference to the ObjectManager class, mainly to allow
*displaying the game in the background of the menu.
*/
class SceneMenuPause : public SceneMenu
{
public:
	/// Construct a pause menu scene.
	SceneMenuPause(Window& _window, SceneStateMachine& _sceneMachine, ObjectManager& __objManager);
	/// Deonstruct a pause menu scene.
	~SceneMenuPause();

	/// Initialize the menu with text and boxes
	void OnCreate() override;
	/// Draw this scene to the window
	void Draw(Window& window) override;

private:
	ObjectManager& objManager;
	sf::RectangleShape alphaGreyOverlay; ///< Used to darken the game in the background.
};

