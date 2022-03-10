#include <SDL.h>

//A1 - Practical 4: Win32 Menu
//Version 05
//10/03/22
//Author: Stefano 
//Basic Game Engine Programming

#include "GameLoad.h"
//#include "GameObject.h"
#include "Player.h"
#include "Obstacle.h"

int main(int argc, char** argv)
{
	//New Object for the class GameLoad
	GameLoad* gameLoad = new GameLoad();
	//GameObject* player1 = new GameObject();
	Player* player1 = new Player(6, "assets/EvilDogWalking.bmp", 200, 600);
	Obstacle* obstacle1 = new Obstacle(1, "assets/Castle.bmp", 170, 30);
	Obstacle* obstacle2 = new Obstacle(1, "assets/bridge.bmp", 140, 380);
	Obstacle* obstacle3 = new Obstacle(1, "assets/WallCastle.bmp", 1000, 0);
	Obstacle* obstacle4 = new Obstacle(1, "assets/WallCastle.bmp", -800, 0);

	gameLoad->load();
	player1->draw();
	obstacle1->draw();
	obstacle2->draw();
	obstacle3->draw();
	obstacle4->draw();
	
	while (gameLoad->running())
	{
		player1->render();
		//player1->update();
		player1->handleEvents();
		obstacle1->render();
		obstacle2->render();
		obstacle3->render();
		obstacle4->render();
	}
	
	//3 seconds of delay
	SDL_Delay(3000);

	gameLoad->clean();

	return 0;
}