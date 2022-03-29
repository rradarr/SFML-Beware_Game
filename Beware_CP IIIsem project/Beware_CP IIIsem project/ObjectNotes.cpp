#include "ObjectNotes.h"

ObjectNotes::ObjectNotes()
{
}

ObjectNotes::~ObjectNotes()
{
	textElements.clear();
}

void ObjectNotes::AddNotes(sf::Texture & texture, int counter)
{
	//setup the note sprite
	notes.setTexture(texture);
	notes.setOrigin(notes.getGlobalBounds().width / 2, notes.getGlobalBounds().height / 2);
	notes.setScale(1.3, 1.3);
	
	notes.setPosition(1200 - notes.getGlobalBounds().width / 2, notes.getGlobalBounds().height / 2);

	sf::Text text;
	sf::FloatRect textSize;

	font.loadFromFile("./arial.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);

	//Set first line of text
	text.setString("-Pick up the stuff!");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(notes.getPosition().x - 40, notes.getPosition().y - notes.getGlobalBounds().height / 3 + 20);

	textElements.push_back(text);

	//Set second line of text
	text.setString("-Stuff left to pick up: " + std::to_string(counter));
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(notes.getPosition().x - 20, notes.getPosition().y - 10);

	textElements.push_back(text);

	//Set third line of text
	text.setString("-Pay for the stuff!");
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(notes.getPosition().x - 40, notes.getPosition().y + 25);

	textElements.push_back(text);
}

sf::Sprite & ObjectNotes::GetSprite()
{
	return notes;
}

std::vector<sf::Text>& ObjectNotes::GetText()
{
	return textElements;
}

void ObjectNotes::Update(int counter)
{
	textElements[1].setString("-Stuff left to pick up: " + std::to_string(counter));
	if (counter < 1)
	{
		textElements[0].setStyle(sf::Text::StrikeThrough);
		textElements[2].setStyle(sf::Text::Underlined);
	}
	else
	{
		textElements[0].setStyle(sf::Text::Regular);
		textElements[2].setStyle(sf::Text::Regular);
	}
}
