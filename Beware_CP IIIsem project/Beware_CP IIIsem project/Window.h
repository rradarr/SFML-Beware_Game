#pragma once

#include <SFML/Graphics.hpp>

/**
*Implementation of a window.
*
*This class represents a window to which
*drawables can be drawn. It creates an interface for
*the sf::RenderWindow.
*/
class Window
{
public:
	/// Construct a new window.
	Window(const std::string& windowName);
	/// Deconstruct the window.
	~Window();

	/// Chceck if the window was closed.
	void Update();
	/// Get sizes of the window.
	sf::Vector2f GetSizes();
	/// Check if the window is open.
	bool IsOpen() const;
	/// Get the current view of the window.
	const sf::View& getView() const;
	/// Get the default view of the window.
	const sf::View& getDefaultView() const;
	/// Set a view as this window's view.
	void setView(const sf::View& view);

	/// Clear the window to color.
	void BeginDraw();
	/// Draw Drawable to the window.
	void Draw(const sf::Drawable& drawable);
	/// Display contents of the window.
	void EndDraw();

private:
	sf::RenderWindow window;
};

