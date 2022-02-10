#pragma once

#include <SDL.h>
#include <iostream>

using namespace std;


class Game
{
public:
	Game();

	bool Start();

	/*bool Game::Start()
	{
		sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
		if (sdlRenderer != nullptr)
		{
			cout << "Create Renderer - success\n";
			return true;
		}
		cout << "Create Renderer - failed\n";
		return false;
	}*/

	void ProcessInput();

	void Update();

	void Draw();

	/*void Game::Draw()
	{
		SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
		SDL_RenderClear(sdlRenderer);
		SDL_RenderPresent(sdlRenderer);
	}*/

	void ShutDown();

	void Run(const char* title, int width, int height, bool fullscreen);

	/*void Game::Run(char* title, int width, int height, bool fullscreen)
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
	}*/

	void Destroy();

	/*void Game::Destroy()
	{
		SDL_DestroyWindow(sdlWindow);
		SDL_DestroyRenderer(sdlRenderer);
		SDL_Quit();
	}*/

	~Game();

private:
	SDL_Window* sdlWindow;
	SDL_Renderer* sdlRenderer;
	bool isGameOver;
};


