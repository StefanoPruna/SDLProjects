#include <SDL.h>

//A1 - Practical 1: Sprite Animation
//Version 02
//24/02/22
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
	GameObject* player4 = new GameObject();
	GameObject* player5 = new GameObject();

	gameLoad->load();
	player1->draw(8, "assets/SwordCatJumping.bmp", 0,  10, 0, 'N', 1.0f, 1);
	player2->draw(8, "assets/SwordCatJumping.bmp", 0, 650, 0, 'N', 1.0f, 1);
	player3->draw(8, "assets/SwordCatJumping.bmp", 450, 300, 0, 'N', 1.5f, 1);
	player4->draw(8, "assets/SwordCatJumping.bmp", 1000, 10, 90, 'H', 1.0f, 1);
	player5->draw(8, "assets/SwordCatJumping.bmp", 1000, 650, 90, 'H', 1.0f, 1);
	while (gameLoad->running())
	{
		player1->update();
		player1->render();
		player2->update();
		player2->render();
		player3->update();
		player3->render();
		player4->update();
		player4->render();
		player5->update();
		player5->render();
	}
	
	//3 seconds of delay
	SDL_Delay(3000);

	gameLoad->clean();

	return 0;
}