#include "ColliderCollection.h"

ColliderCollection::ColliderCollection()
{
}

ColliderCollection::~ColliderCollection()
{
	collection.clear();
}

void ColliderCollection::AddCollider(sf::Sprite& parent, int type)
{
	
	if (type == 0)
	{
		return;
	}
	else if (type == 1 || type == 3) //basic shelve or entrance
	{
		sf::RectangleShape collider;
		collider.setSize(sf::Vector2f(parent.getGlobalBounds().width, parent.getGlobalBounds().height / 2));
		collider.setOrigin(collider.getGlobalBounds().width / 2, collider.getGlobalBounds().height / 2);
		collider.setRotation(parent.getRotation());
		sf::Vector2f offset;
		if (collider.getRotation() == 0)
		{
			offset.x = 0;
			offset.y = parent.getGlobalBounds().height / -4;
		}
		else if (collider.getRotation() == 90)
		{
			offset.x = parent.getGlobalBounds().width / 4;
			offset.y = 0;
		}
		else if (collider.getRotation() == 180)
		{
			offset.x = 0;
			offset.y = parent.getGlobalBounds().height / 4;
		}
		else if (collider.getRotation() == 270)
		{
			offset.x = parent.getGlobalBounds().width / -4;
			offset.y = 0;
		}
		collider.setPosition(parent.getPosition() + offset);
		//debug
		collider.setFillColor(sf::Color::Transparent);
		collider.setOutlineThickness(-1);
		collider.setOutlineColor(sf::Color::Black);
		//debug
		collection.push_back(collider);
	}
	else if (type == 2 || type == 4)
	{
		sf::RectangleShape collider1, collider2;

		collider1.setSize(sf::Vector2f(parent.getGlobalBounds().width, parent.getGlobalBounds().height / 2));
		collider2.setSize(sf::Vector2f(parent.getGlobalBounds().width / 2, parent.getGlobalBounds().height));

		collider1.setOrigin(collider1.getGlobalBounds().width / 2, collider1.getGlobalBounds().height / 2);
		collider2.setOrigin(collider2.getGlobalBounds().width / 2, collider2.getGlobalBounds().height / 2);

		sf::Vector2f offset1(0, 0);
		sf::Vector2f offset2(0, 0);
		if (parent.getRotation() == 0)
		{
			offset1.y = parent.getGlobalBounds().width / -4;

			offset2.x = parent.getGlobalBounds().height / 4;
		}
		else if (parent.getRotation() == 90)
		{
			offset1.y = parent.getGlobalBounds().height / 4;

			offset2.x = parent.getGlobalBounds().width / 4;
		}
		else if (parent.getRotation() == 180)
		{
			offset1.y = parent.getGlobalBounds().height / 4;

			offset2.x = parent.getGlobalBounds().width / -4;
		}
		else if (parent.getRotation() == 270)
		{
			offset1.y = parent.getGlobalBounds().height / -4;

			offset2.x = parent.getGlobalBounds().width / -4;
		}
		collider1.setPosition(parent.getPosition() + offset1);
		collider2.setPosition(parent.getPosition() + offset2);
		//debug
		collider1.setFillColor(sf::Color::Transparent);
		collider2.setFillColor(sf::Color::Transparent);
		collider1.setOutlineThickness(-1);
		collider2.setOutlineThickness(-1);
		collider1.setOutlineColor(sf::Color::Black);
		collider2.setOutlineColor(sf::Color::Black);
		//debug

		collection.push_back(collider1);
		collection.push_back(collider2);
	}
	
}

std::vector<sf::RectangleShape>& ColliderCollection::GetCollection()
{
	return collection;
}

sf::RectangleShape& ColliderCollection::operator[](unsigned int id)
{
	return collection[id];
}
