#include "SceneMenu.h"

SceneMenu::SceneMenu(Window& _window, SceneStateMachine& _sceneMachine): window(_window), sceneMachine(_sceneMachine), positionID(0)
{
}

SceneMenu::~SceneMenu()
{
	selectableMenuElements.clear();
}

void SceneMenu::OnCreate()
{
	sf::Text text;
	sf::RectangleShape rect;
	sf::FloatRect textSize;
	
	font.loadFromFile("./arial.ttf");
	text.setFont(font);

	//Set Play text
	text.setFont(font);
	text.setString("Play");
	textSize = text.getLocalBounds();
	text.setOrigin(textSize.width / 2, textSize.height / 2);
	text.setFillColor(sf::Color::Red);
	text.setPosition(sf::Vector2f(window.GetSizes().x / 2, (window.GetSizes().y / 3) * 1));

	//Set Play box
	rect.setSize(sf::Vector2f(textSize.width, textSize.height));
	rect.setFillColor(sf::Color::Color(80, 80, 80));
	rect.setOrigin(rect.getLocalBounds().width / 2, rect.getLocalBounds().height / 2);
	rect.setScale(3, 2);
	rect.setPosition(window.GetSizes().x / 2, (window.GetSizes().y / 3) * 1 + 5);

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

void SceneMenu::OnDestroy()
{
}

void SceneMenu::SetNextScene(unsigned int _id)
{
	nextScene = _id;
}

void SceneMenu::ProcessInput()
{
	input.Update();
}

void SceneMenu::Update(float deltaTime)
{
	switch (positionID)
	{
	case 0: 
		if (input.IsKeyHeld(Input::Key::Enter))
		{
			sceneMachine.SwithTo(nextScene);
		}
		else if (input.IsKeyHeld(Input::Key::Down))
		{
			selectableMenuElements[positionID].second.setFillColor(sf::Color::Black);
			selectableMenuElements[positionID].first.setFillColor(sf::Color::Color(40, 40, 40));
			positionID = 1;
			selectableMenuElements[positionID].second.setFillColor(sf::Color::Red);
			selectableMenuElements[positionID].first.setFillColor(sf::Color::Color(80, 80, 80));
		}
		break;
	case 1:
		if (input.IsKeyHeld(Input::Key::Enter))
		{
			sceneMachine.StopRunning();
		}
		else if (input.IsKeyHeld(Input::Key::Up))
		{
			selectableMenuElements[positionID].second.setFillColor(sf::Color::Black);
			selectableMenuElements[positionID].first.setFillColor(sf::Color::Color(40, 40, 40));
			positionID = 0;
			selectableMenuElements[positionID].second.setFillColor(sf::Color::Red);
			selectableMenuElements[positionID].first.setFillColor(sf::Color::Color(80, 80, 80));
		}
		break;
	default:
		break;
	}
}

void SceneMenu::Draw(Window & window)
{
	for (auto elem : selectableMenuElements) {
		window.Draw(elem.first);
		window.Draw(elem.second);
	}
}

