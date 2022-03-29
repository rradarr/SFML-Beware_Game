#pragma once

#include "SceneMenuPause.h"
#include "ObjectManager.h"

/**
*This is an implementation of the stats menu scene also called the final scene.
*
*It inherits from SceneMenu and overrides some of it's
*methods to achieve a different visual composition.
*It holds a reference to the ObjectManager class, mainly to allow
*displaying information about the number of infections and
*to reset the game when the Play aagain option is selected.
*/
class SceneMenuStats : public SceneMenu
{
public:
	/// Construct a final scene
	SceneMenuStats(Window& _window, SceneStateMachine& _sceneMachine, ObjectManager & _manager);
	/// Deconstruct the final scene
	~SceneMenuStats();

	/// Update the infections value in the text
	void OnActivate() override;
	/// Reset the game to prepare it for another playtrough
	void OnDeactivate() override;
	/// Set up the text and buttons of the scene
	void OnCreate() override;
	/// Draw the scene to the window
	void Draw(Window& window) override;

private:
	ObjectManager& objManager;

	std::vector<sf::Text> textElements;
};

