#pragma once
#include "GameLoad.h"

class Rectangle : GameLoad
{
public:
	Rectangle(Uint8 r, Uint8 g, Uint8 b);
	~Rectangle();
	void drawing(SDL_Rect rect);

private:
	SDL_Color rectColor;
};

