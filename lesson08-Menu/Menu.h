#pragma once
#include <SDL.h>
#include <Windows.h>

class Menu
{
public:
	Menu();
	~Menu();
	void get_menu();
	int DisplayDialogBox();

private:
	HWND _window;
	HMENU _menu;
	SDL_Window* sdlWindow2;
	SDL_Renderer* m_Renderer2;
};

