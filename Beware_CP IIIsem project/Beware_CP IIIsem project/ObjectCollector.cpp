#include "ObjectCollector.h"

ObjectCollector::ObjectCollector(sf::Sprite & parent, bool _isExit) : active(!_isExit), counter(0), isExit(_isExit)
{
	float exitCorrection = 0;
	if (isExit)
	{
		exitCorrection = 90;
	}

	collectorZone.setSize(sf::Vector2f(parent.getGlobalBounds().width / 1.7, parent.getGlobalBounds().height / 8));
	shelfOverlay.setSize(sf::Vector2f(parent.getGlobalBounds().width, parent.getGlobalBounds().height / 2));

	collectorZone.setOrigin(collectorZone.getGlobalBounds().width / 2, collectorZone.getGlobalBounds().height / 2);
	shelfOverlay.setOrigin(shelfOverlay.getGlobalBounds().width / 2, shelfOverlay.getGlobalBounds().height / 2);

	collectorZone.setRotation(parent.getRotation() + exitCorrection);
	shelfOverlay.setRotation(parent.getRotation() + exitCorrection);

	sf::Vector2f offset1(0, 0);
	sf::Vector2f offset2(0, 0);
	if (parent.getRotation() + exitCorrection == 0)
	{
		offset1.y = parent.getGlobalBounds().height / 16;

		offset2.y = parent.getGlobalBounds().height / -4;
	}
	else if (parent.getRotation() + exitCorrection == 90)
	{
		offset1.x = parent.getGlobalBounds().width / -16;

		offset2.x = parent.getGlobalBounds().width / 4;
	}
	else if (parent.getRotation() + exitCorrection == 180)
	{
		offset1.y = parent.getGlobalBounds().height / -16;

		offset2.y = parent.getGlobalBounds().height / 4;
	}
	else if (parent.getRotation() + exitCorrection == 270)
	{
		offset1.x = parent.getGlobalBounds().width / 16;

		offset2.x = parent.getGlobalBounds().width / -4;
	}
	collectorZone.setPosition(parent.getPosition() + offset1);
	shelfOverlay.setPosition(parent.getPosition() + offset2);
	//debug
	collectorZone.setFillColor(sf::Color::Transparent);
	collectorZone.setOutlineThickness(-1);
	collectorZone.setOutlineColor(sf::Color::Black);
	//debug

	shelfOverlay.setFillColor(sf::Color(255, 255, 255, 0));
}

ObjectCollector::~ObjectCollector()
{
}

bool ObjectCollector::Intersects(sf::RectangleShape playerCollider)
{
	if (!isExit)
	{
		if (collectorZone.getGlobalBounds().intersects(playerCollider.getGlobalBounds()))
		{
			active = false;
			shelfOverlay.setFillColor(sf::Color::Transparent);
			return true;
		}
		return false;
	}
	else
	{
		if (active && collectorZone.getGlobalBounds().intersects(playerCollider.getGlobalBounds()))
		{
			shelfOverlay.setFillColor(sf::Color::Transparent);
			return true;
		}
		return false;
	}
}

bool ObjectCollector::GetActive()
{
	return active;
}

sf::RectangleShape & ObjectCollector::GetOverlay()
{
	if (active)
	{
		counter += 5;
		counter = counter % 200;
		shelfOverlay.setFillColor(sf::Color(225, 225, 225, counter));
		return shelfOverlay;
	}
	return shelfOverlay;
}

bool ObjectCollector::IsExit()
{
	return isExit;
}

void ObjectCollector::ActivateExit()
{
	active = true;
}

sf::RectangleShape & ObjectCollector::GetCollector()
{
	return collectorZone;
}
