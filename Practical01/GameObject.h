#pragma once
#include "GameLoad.h"

//GameLoad is a subclass of GameObject
class GameObject : GameLoad
{
public:
	GameObject();
	~GameObject();
	void draw(const char* path, int m_pox_x, int m_pos_y);
	void render();

private:
	SDL_Surface* m_Surface;
	SDL_Texture* m_Texture;

	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};

