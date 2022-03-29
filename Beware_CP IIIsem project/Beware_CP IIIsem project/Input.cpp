#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::Update()
{
	lastFrameKeys.SetMask(thisFrameKeys);

	thisFrameKeys.SetBit((int)Key::Up, sf::Keyboard::isKeyPressed(sf::Keyboard::W));
	thisFrameKeys.SetBit((int)Key::Right, sf::Keyboard::isKeyPressed(sf::Keyboard::D));
	thisFrameKeys.SetBit((int)Key::Down, sf::Keyboard::isKeyPressed(sf::Keyboard::S));
	thisFrameKeys.SetBit((int)Key::Left, sf::Keyboard::isKeyPressed(sf::Keyboard::A));
	thisFrameKeys.SetBit((int)Key::E, sf::Keyboard::isKeyPressed(sf::Keyboard::E));
	thisFrameKeys.SetBit((int)Key::M, sf::Keyboard::isKeyPressed(sf::Keyboard::M));
	thisFrameKeys.SetBit((int)Key::Esc, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	thisFrameKeys.SetBit((int)Key::Enter, sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
}

bool Input::IsKeyHeld(Key keycode)
{
	return thisFrameKeys.GetBit((int)keycode);
}

bool Input::IsKeyDown(Key keycode)
{
	return !lastFrameKeys.GetBit((int)keycode) && thisFrameKeys.GetBit((int)keycode);
}

bool Input::IsKeyUp(Key keycode)
{
	return lastFrameKeys.GetBit((int)keycode) && !thisFrameKeys.GetBit((int)keycode);;
}
