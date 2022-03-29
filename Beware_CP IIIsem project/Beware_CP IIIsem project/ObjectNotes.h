#pragma once

#include "SFML/Graphics.hpp"

/**
*Implementation of the player character's notes.
*/
class ObjectNotes
{
public:
	/// Construct notes.
	ObjectNotes();
	/// Deconstruct notes.
	~ObjectNotes();

	/// Setup the notes.
	void AddNotes(sf::Texture & texture, int counter);
	/// Get the sprite of the notes.
	sf::Sprite & GetSprite();
	/// Get the text elements of the notes.
	std::vector<sf::Text> & GetText();

	/// Update the item counter.
	void Update(int counter);

private:
	sf::Sprite notes;

	sf::Font font;
	std::vector<sf::Text> textElements;

};

