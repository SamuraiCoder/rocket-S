/*
	RocketS-Engine.
	by Sam Alonso. 2019.

*/

#include "Game.h"

int main(int argc, char** argv)
{
	//Init graphics server
	if (GM->Init())
		GM->Setup(1024, 720);

	//Init time server
	if (TM->Init())
		TM->Setup();
	
	//Create the game
	Game myGame;
	myGame.update();

	GM->cleanup(GM->GetSDLRenderer());
	GM->cleanup(GM->GetSDLWindow());
	
	return 0;
}