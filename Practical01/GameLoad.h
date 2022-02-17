#pragma once
#include <SDL.h>

class GameLoad
{
public:
	GameLoad();
	~GameLoad();
	void load();
	void clean();

protected:
	static SDL_Renderer* m_Renderer;

private:
	SDL_Window* sdlWindow;
};

