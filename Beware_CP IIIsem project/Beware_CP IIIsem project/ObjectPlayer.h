#pragma once

#include "SFML/Graphics.hpp"

/**
*This class represents a player character.
*
*It stores the player sprite and collider box. It
*provides mehods to use the player in the ObjectManager.
*/
class ObjectPlayer
{
public:
	/// Construct a new player object.
	ObjectPlayer();
	/// Deconstruct the player.
	~ObjectPlayer();

	/// Set a texture to the player.
	void SetTexture(sf::Texture& texture);
	/// Set player's position.
	void SetPosition(float x, float y);
	/// Move the player by some distance and remember this movement.
	void Move(float _xMove, float _yMove);
	/// Move the player by some distance. This method doesn't memorize the movement.
	void ProbeMove(float _xMove, float _yMove);
	/// Set the scale of the player.
	void SetScale(float scaleX, float scaleY);
	/// Put on/take off the mask.
	void ChangeMask();

	/// Get player's collider box.
	sf::RectangleShape& GetCollider();
	/// Get player sprite.
	sf::Sprite& GetSprite();
	/// Get the collider for drawing. Used for debugging.
	sf::RectangleShape& GetColliderDrawable();
	/// Get the mask status.
	bool GetMask();

	/// Get the last x movement.
	float GetxMove();
	/// Get the last y movement.
	float GetyMove();

private:
	/// Set origins of the player and collider box.
	void setOrigins();
	sf::Sprite sprite;
	sf::IntRect textureRect;
	sf::RectangleShape collider;

	bool mask;

	float xMove;
	float yMove;
};

