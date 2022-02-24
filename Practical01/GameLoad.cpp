#include "GameLoad.h"
#include <iostream>

using namespace std;

SDL_Renderer* GameLoad::m_Renderer = nullptr;

GameLoad::GameLoad()
{
	isRunning = false;
}

GameLoad::~GameLoad()
{

}

void GameLoad::load()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Initialize SDL - success \n";
		// a window for rendering

		sdlWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 940, SDL_WINDOW_SHOWN);
		m_Renderer = SDL_CreateRenderer(sdlWindow, 0, -1);
		if (m_Renderer != nullptr)
			cout << "Create Renderer - success \n";
		isRunning = true;
	}
}

void GameLoad::clean()
{
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();
}

bool GameLoad::running()
{
	return isRunning;
}
