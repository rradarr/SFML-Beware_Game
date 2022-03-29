#include "SceneMenuStats.h"

SceneMenuStats::SceneMenuStats(Window & _window, SceneStateMachine & _sceneMachine, ObjectManager & _manager) : SceneMenu(_window, _sceneMachine), objManager(_manager)
{
}

SceneMenuStats::~SceneMenuStats()
{
	textElements.clear();
}

void SceneMenuStats::OnActivate()
{
	textElements[2].setString("You infected " + std::to_string(objManager.GetInfections()) + " people.");
}

void SceneMenuStats::OnDeactivate()
{
	objManager.ResetGame();
}

void SceneMenuStats::OnCreate()
{
	sf::Text text;
	sf::RectangleShape rect;
	sf::FloatRect textSize;

	font.loadFromFile("./arial.ttf");
	text.setFont(font);

	//Set Play text
	text.setFont(font);
	text.setString("Play again");
	textSize = text.getLocalBounds();
	text.setOrigin(textSize.width / 2, textSize.height / 2);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(window.GetSizes().x / 2 - 500, (window.GetSizes().y / 3) * 1));

	//Set Play box
	rect.setSize(sf::Vector2f(textSize.width, textSize.height));
	rect.setFillColor(sf::Color::Color(80, 80, 80));
	rect.setOrigin(rect.getLocalBounds().width / 2, rect.getLocalBounds().height / 2);
	rect.setScale(3, 2);
	rect.setPosition(window.GetSizes().x / 2 - 500, (window.GetSizes().y / 3) * 1 + 5);

	selectableMenuElements.push_back(std::pair<sf::RectangleShape, sf::Text>(rect, text));

	//Set Exit text
	text.setString("Exit");
	textSize = text.getLocalBounds();
	text.setOrigin(textSize.width / 2, textSize.height / 2);
	text.setFillColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(window.GetSizes().x / 2 - 500, (window.GetSizes().y / 3) * 2));


	//Set Exit box
	rect.setFillColor(sf::Color::Color(40, 40, 40));
	rect.setPosition(window.GetSizes().x / 2 - 500, (window.GetSizes().y / 3) * 2 + 7);

	selectableMenuElements.push_back(std::pair<sf::RectangleShape, sf::Text>(rect, text));

	//Set the ending text
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setString(	"You got everything off your shopping list! But:\n\n"
					"It turns out that before you went to this shop you were\n"
					"infected with COVID-19.\n\n"
					"Even though you had no symptoms, by not being causious,\n"
					"not following the rules of physical distancing and\n"
					"not wering a mask you infected other people that might\n"
					"not get through the infection with such luck as yours.\n"
					"Care about others and");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(window.GetSizes().x / 3 * 2, text.getGlobalBounds().height / 2 + 100);

	textElements.push_back(text);

	//Set the title text
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Black);
	text.setString("BEWARE");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(window.GetSizes().x / 3 * 2, window.GetSizes().y / 2 - 40);

	textElements.push_back(text);

	//Set infected info
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setString("You infected " + std::to_string(objManager.GetInfections()) + " people.");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(window.GetSizes().x / 3 * 2, window.GetSizes().y / 2 + 80);

	textElements.push_back(text);

	//Set mask info
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setString("TIP: You can put on your mask with M.");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(window.GetSizes().x / 3 * 2, window.GetSizes().y / 3 * 2 + 80);

	textElements.push_back(text);
}

void SceneMenuStats::Draw(Window & window)
{
	sf::View view = window.getView();

	window.setView(window.getDefaultView());
	for (auto & elem : selectableMenuElements)
	{
		window.Draw(elem.first);
		window.Draw(elem.second);
	}
	for (auto & elem : textElements)
	{
		window.Draw(elem);
	}
	window.setView(view);
}
