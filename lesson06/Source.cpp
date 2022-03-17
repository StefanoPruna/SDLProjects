//A1 - Practical 4: Text and Sounds
//Version 06
//17/03/22
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
	TextScreen* scoreText = new TextScreen(20, "assets/arial.ttf", 80, 20);
	Sound* soundFX = new Sound("assets/mwand.wav");
	Sound* musicBK = new Sound("assets/music.mp3");

	//if it's -1) = infinity, if it's 0) == play once, if it's 1) = play twice, if it's 2) = play three times
	//In this case, it'll play once
	if (Mix_PlayChannel(-1, soundFX->wave(), 0) == -1)
		cerr << "Failed to play effect\n";
		
	//if it's 0) or 1) = play once, if it's 2) play twice, if it's -1) plays infinity
	//In this case, it'll play once
	if (Mix_PlayMusic(musicBK->music(), 1) == -1)
		cerr << "Failed to play music.\n";

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
	
	int score = 1000;

	while (gameLoad->running())
	{
		player1->render();
		//player1->update();
		player1->handleEvents();
		obstacle1->render();
		obstacle2->render();
		obstacle3->render();
		obstacle4->render();

		scoreText->update("Score: " + to_string(score));
		scoreText->render();

		score--;

		if (player1->alarm())
			Mix_PlayChannel(-1, soundFX->wave(), 0);
	}
	
	//3 seconds of delay
	SDL_Delay(3000);

	gameLoad->clean();

	return 0;
}