#pragma once

#include <SFML/Graphics.hpp>
#include "BitMask.h"

/**
*Implementation of keyboard input from user.
*
*This class provides an interface between the program
*and the user via the keyboard. It allows for differentiation
*of keys that are held from a key that was just pressed
*and just released with the use of bitmasks.
*
*@see BitMask
*/
class Input
{
public:
	/// Construct an input interface
	Input();

	/// Deconstruct an input interface
	~Input();

	/**
	*Keybindings used by the program.
	*/
	enum class Key
	{
		None = 0,	///< No key
		Up = 1,		///< W key
		Right = 2,	///< D key
		Down = 3,	///< S key
		Left = 4,	///< A key
		E = 5,		///< E key
		M = 6,		///< M key
		Esc = 7,	///< Escape key
		Enter = 8	///< Enter key
	};

	/// Save last frame's inputs and sets this frame's inputs
	void Update();

	/// Chceck if the key specifed by keycode was down last frame and still is down
	bool IsKeyHeld(Key keycode);
	/// Check if the key specifed by keycode was up last frame and is down
	bool IsKeyDown(Key keycode);
	/// Check if the key specifed by keycode was down last frame and is up
	bool IsKeyUp(Key keycode);

private:
	BitMask thisFrameKeys;
	BitMask lastFrameKeys;
};

