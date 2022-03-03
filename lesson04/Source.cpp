#include <SDL.h>

//A1 - Practical 3: Create a simple game
//Version 03
//03/03/22
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
	Obstacle* obstacle1 = new Obstacle(1, "assets/Castle.bmp", 20, 30);
	Obstacle* obstacle2 = new Obstacle(1, "assets/bridge.bmp", 40, 350);

	gameLoad->load();
	player1->draw();
	obstacle1->draw();
	obstacle2->draw();
	
	while (gameLoad->running())
	{
		player1->render();
		player1->update();
		player1->handleEvents();
		obstacle1->render();
		obstacle2->render();
	}
	
	//3 seconds of delay
	SDL_Delay(3000);

	gameLoad->clean();

	return 0;
}