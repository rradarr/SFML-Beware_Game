#include "Game.h"


int main()
{
	{ //additional braket

		Game game;

		while (game.IsRunning())
		{
			game.ProcessInput();
			game.Update();
			game.LateUpdate();
			game.Draw();
			game.GetDeltaTime();
		}

	} //additional braket
}


//ask bout IO
//and report comments stuff
//and "Dynamic memory allocation"