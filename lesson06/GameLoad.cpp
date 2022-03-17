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

		
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
		SDL_RenderClear(m_Renderer);

		isRunning = true;

		if (TTF_Init() == -1)
			cerr << "Failed to initialized SDL_ttf.\n";

		//Initialized SDL mixer
		SDL_Init(SDL_INIT_AUDIO);
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
