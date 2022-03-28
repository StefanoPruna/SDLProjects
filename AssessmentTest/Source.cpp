//A1 - Practical 4: Text and Sounds
//Version 07
//24/03/22
//Author: Stefano 
//Basic Game Engine Programming

#include <SDL.h>
#include "GameLoad.h"
#include "Player.h"
#include "Obstacle.h"
#include "TextScreen.h"
#include "Sound.h"
#include "GameObject.h"
#include <iostream>
#include "Rectangle.h"
#include "Enemy.h"

using namespace std;

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
	TextScreen* scoreText = new TextScreen(20, "assets/arial.ttf", 600, 20);
	//Sound* soundFX = new Sound("assets/mwand.wav");
	Sound* musicBK = new Sound("assets/music.mp3");
	//Rectangle* rect1 = new Rectangle(25, 255, 25);
	Rectangle* rectPlayer = new Rectangle(255, 255, 255);//white rectangle behind the player
	Rectangle* RectText = new Rectangle(200, 200, 255);
	Enemy* enemy1 = new Enemy(4, "assets/evilMouse.bmp", 900, 650);


	//if it's -1) = infinity, if it's 0) == play once, if it's 1) = play twice, if it's 2) = play three times
	//In this case, it'll play once
	/*if (Mix_PlayChannel(-1, soundFX->wave(), 0) == -1)
		cerr << "Failed to play effect\n";*/
		
	//if it's 0) or 1) = play once, if it's 2) play twice, if it's -1) plays infinity
	//In this case, it'll play once
	/*if (Mix_PlayMusic(musicBK->music(), 1) == -1)
		cerr << "Failed to play music.\n";*/

	//to stop the music and sound
	/*Mix_FreeChunk(soundFX->wave());
	Mix_FreeMusic(musicBK->music());*/

	scoreText->draw();

	gameLoad->load();
	player1->draw();
	obstacle1->draw();
	obstacle2->draw();
	obstacle3->draw();
	obstacle4->draw();
	enemy1->draw();
	
	//position of the rectangle first 2, size of it the second two
	SDL_Rect rectDraw1 = { 400, 850, 50, 50 };
	SDL_Rect rectDrawText = { 660, 20, 50, 25 };


	while (gameLoad->running())
	{
		player1->render();
		//player1->update();
		player1->handleEvents();
		obstacle1->render();
		obstacle2->render();
		obstacle3->render();
		obstacle4->render();
		enemy1->render();
		enemy1->enemyEvents();		
		
		RectText->drawing(rectDrawText);
		scoreText->update("Score: " + to_string(player1->score));
		scoreText->render();

		//rect1->drawing(rectDraw1);

		//To clean the effect of Player
		rectPlayer->drawing(player1->getPosPlayer());


		/*if (player1->alarm())
			Mix_PlayChannel(-1, soundFX->wave(), 0);*/
	}
	
	//3 seconds of delay
	SDL_Delay(3000);

	gameLoad->clean();

	return 0;
}