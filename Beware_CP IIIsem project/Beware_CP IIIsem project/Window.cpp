#include "Window.h"

Window::Window(const std::string & windowName): window(sf::VideoMode(1200, 800), windowName, sf::Style::Close)
{
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120); //0 for debug + change in collector
}

Window::~Window()
{
	window.close();
}

void Window::Update()
{
	sf::Event event;
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

sf::Vector2f Window::GetSizes()
{
	return sf::Vector2f(window.getSize());
}

void Window::BeginDraw()
{
	window.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable & drawable)
{
	window.draw(drawable);
}

void Window::EndDraw()
{
	window.display();
}

bool Window::IsOpen() const
{
	return window.isOpen();
}

const sf::View& Window::getView() const
{
	return window.getView();
}

const sf::View & Window::getDefaultView() const
{
	return window.getDefaultView();
}

void Window::setView(const sf::View& view)
{
	window.setView(view);
}
