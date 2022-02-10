#include "Game.h"
#include <iostream>

using namespace std;

//Constructor
Game::Game()
{
	//set SDL window pointer to null
	sdlWindow = nullptr;

	//set the SDL renderer pointer to null
	sdlRenderer = nullptr;

	//initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		isGameOver = true;
		cout << "Initialize SDL - failed\n";
	}
	else
	{
		isGameOver = false;
		cout << "Initialize SDL - success\n";
	}


}

//Destructor
Game::~Game()
{

}

bool Game::Start()
{
	sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
	if (sdlRenderer != nullptr)
	{
		cout << "Create Renderer - success\n";
		return true;
	}
	cout << "Create Renderer - failed\n";
	return false;
}

void Game::Draw()
{
	SDL_SetRenderDrawColor(sdlRenderer, 200, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);
}

void Game::Run(const char* title, int width, int height, bool fullscreen)
{
	int creationFlag = 0;

	if (!fullscreen)
		creationFlag = SDL_WINDOW_SHOWN;
	else
		creationFlag = SDL_WINDOW_FULLSCREEN;

	sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, creationFlag);

	if (sdlWindow != nullptr && Start())
	{
		cout << "Create Window - success\n";
		while (!isGameOver)
		{
			ProcessInput();
			Update();
			Draw();
		}
	}

	cout << "Create Window - failed\n";

	ShutDown();
	Destroy();
}

void Game::Destroy()
{
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_Quit();
}

void Game::ProcessInput()
{

}

void Game::Update()
{

}

void Game::ShutDown()
{

}
