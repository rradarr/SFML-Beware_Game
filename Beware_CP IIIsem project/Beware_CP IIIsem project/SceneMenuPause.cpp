#include "SceneMenuPause.h"

SceneMenuPause::SceneMenuPause(Window & _window, SceneStateMachine & _sceneMachine, ObjectManager& _objManager) : SceneMenu(_window, _sceneMachine), objManager(_objManager)
{
	alphaGreyOverlay.setSize(sf::Vector2f(window.GetSizes().x, window.GetSizes().y));
	alphaGreyOverlay.setFillColor(sf::Color::Color(0, 0, 0, 100));
}

SceneMenuPause::~SceneMenuPause()
{
}

void SceneMenuPause::OnCreate()
{
	sf::Text text;
	sf::RectangleShape rect;
	sf::FloatRect textSize;

	font.loadFromFile("./arial.ttf");
	text.setFont(font);

	//Set Play text
	text.setFont(font);
	text.setString("Continue");
	textSize = text.getLocalBounds();
	text.setOrigin(textSize.width / 2, textSize.height / 2);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(window.GetSizes().x / 2, (window.GetSizes().y / 3) * 1));

	//Set Play box
	rect.setSize(sf::Vector2f(textSize.width, textSize.height));
	rect.setFillColor(sf::Color::Color(80, 80, 80));
	rect.setOrigin(rect.getLocalBounds().width / 2, rect.getLocalBounds().height / 2);
	rect.setScale(1.5f, 1.5f);
	rect.setPosition(window.GetSizes().x / 2, (window.GetSizes().y / 3) * 1 + 7);

	selectableMenuElements.push_back(std::pair<sf::RectangleShape, sf::Text>(rect, text));

	//Set Exit text
	text.setString("Exit");
	textSize = text.getLocalBounds();
	text.setOrigin(textSize.width / 2, textSize.height / 2);
	text.setFillColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(window.GetSizes().x / 2, (window.GetSizes().y / 3) * 2));


	//Set Exit box
	rect.setFillColor(sf::Color::Color(40, 40, 40));
	rect.setPosition(window.GetSizes().x / 2, (window.GetSizes().y / 3) * 2 + 7);

	selectableMenuElements.push_back(std::pair<sf::RectangleShape, sf::Text>(rect, text));
}

void SceneMenuPause::Draw(Window & window)
{
	sf::View view = window.getView();
	
	for (auto & tile : objManager.GetLevel().GetCollection())
	{
		window.Draw(tile);
	}
	for (auto & client : objManager.GetClients())
	{
		window.Draw(client);
	}
	window.Draw(objManager.GetPlayer());

	window.setView(window.getDefaultView());

	window.Draw(objManager.GetUI().GetSprite());
	for (auto & textElem : objManager.GetUI().GetText())
	{
		window.Draw(textElem);
	}

	window.Draw(alphaGreyOverlay);
	for (auto & elem : selectableMenuElements)
	{
		window.Draw(elem.first);
		window.Draw(elem.second);
	}

	window.setView(view);
}
