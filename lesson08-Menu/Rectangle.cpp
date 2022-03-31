#include "Rectangle.h"

Rectangle::Rectangle(Uint8 r, Uint8 g, Uint8 b)
{
	rectColor = { r, g, b, 255 };
}
Rectangle::~Rectangle()
{

}

void Rectangle::drawing(SDL_Rect rect)
{
	SDL_SetRenderDrawColor(m_Renderer, rectColor.r, rectColor.g, rectColor.b, 255);
	SDL_RenderFillRect(m_Renderer, &rect);
}
