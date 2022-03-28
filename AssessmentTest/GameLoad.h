#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class GameLoad
{
public:
	GameLoad();
	~GameLoad();
	void load();
	void clean();
	bool running();

protected:
	static SDL_Renderer* m_Renderer;

private:
	SDL_Window* sdlWindow;
	bool isRunning;
};

