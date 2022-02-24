#include <SDL.h>

//A1 - Practical 1: Sprite Animation
//Version 01
//17/02/22
//Author: Stefano 
//Basic Game Engine Programming

#include "GameLoad.h"
#include "GameObject.h"

int main(int argc, char** argv)
{
	//New Object for the class GameLoad
	GameLoad* gameLoad = new GameLoad();
	GameObject* player1 = new GameObject();
	GameObject* player2 = new GameObject();
	GameObject* player3 = new GameObject();

	gameLoad->load();
	player2->draw("assets/TheEvilDog.bmp", 0, 0);
	player1->draw("assets/TheEvilDog.bmp", 500, 800);
	player3->draw("assets/TheEvilDog.bmp", 80, 40);
	player2->render();
	player1->render();
	player3->render();

	//3 seconds of delay
	SDL_Delay(3000);

	gameLoad->clean();

	return 0;
}