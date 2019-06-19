/*
	RocketS-Engine.
	by Sam Alonso. 2019.

*/

#include "Game.h"

#ifdef _DEBUG
	#include "vld.h"
#endif

int main(int argc, char** argv)
{
	//Init graphics server
	Graphics::CGraphicsManager::Instance();
	Graphics::CGraphicsManager::Instance().Setup(1024, 720);

	//Init time server
	GameUtils::CTimeManager::Instance();

	//Create the game
	Game myGame;
	myGame.update();

	return 0;
}