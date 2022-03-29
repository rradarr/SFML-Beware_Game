#include "ObjectPlayer.h"

ObjectPlayer::ObjectPlayer() : mask(false)
{
}

ObjectPlayer::~ObjectPlayer()
{
}

void ObjectPlayer::SetTexture(sf::Texture& texture)
{
	textureRect = sf::IntRect(0, 0, 10, 15);
	sprite.setTextureRect(textureRect);
	sprite.setTexture(texture);
	collider.setSize(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 1.5));

	//debug
	collider.setFillColor(sf::Color::Transparent);
	collider.setOutlineColor(sf::Color::Black);
	collider.setOutlineThickness(-1);
	//debug

	setOrigins();
}

void ObjectPlayer::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
	collider.setPosition(x, y);
}

void ObjectPlayer::Move(float _xMove, float _yMove)
{
	xMove = _xMove;
	yMove = _yMove;
	_xMove += sprite.getPosition().x;
	_yMove += sprite.getPosition().y;
	SetPosition(_xMove, _yMove);
}

void ObjectPlayer::ProbeMove(float _xMove, float _yMove)
{
	_xMove += sprite.getPosition().x;
	_yMove += sprite.getPosition().y;
	SetPosition(_xMove, _yMove);
}

void ObjectPlayer::SetScale(float scaleX, float scaleY)
{
	sprite.setScale(scaleX, scaleY);
	collider.setScale(scaleX, scaleY);
}

void ObjectPlayer::ChangeMask()
{
	mask = !mask;
	if (textureRect.left == 0)
	{
		textureRect.left = 10;
	}
	else if (textureRect.left == 10)
	{
		textureRect.left = 0;
	}
	sprite.setTextureRect(textureRect);
}

sf::RectangleShape& ObjectPlayer::GetCollider()
{
	return collider;
}

sf::Sprite& ObjectPlayer::GetSprite()
{
	return sprite;
}

sf::RectangleShape& ObjectPlayer::GetColliderDrawable()
{
	return collider;
}

bool ObjectPlayer::GetMask()
{
	return mask;
}

float ObjectPlayer::GetxMove()
{
	return xMove;
}

float ObjectPlayer::GetyMove()
{
	return yMove;
}

void ObjectPlayer::setOrigins()
{
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	collider.setOrigin(collider.getGlobalBounds().width / 2, collider.getGlobalBounds().height / 2);
}
