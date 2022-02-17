#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::draw(const char* path, int m_pos_x, int m_pos_y)
{
	//Create Surface from an image
	m_Surface = SDL_LoadBMP(path);
	if (m_Surface != nullptr)
		cout << "Load Surface - success\n";

	//Create Texture from Surface
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);
	if (m_Texture != nullptr)
		cout << "Create texture from surface - success\n";

	//Set the source rectangle
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	m_sourceRectangle.w = 500;
	m_sourceRectangle.h = 690;

	//Set the destination rectangle
	m_destinationRectangle.x = m_pos_x;// 100;
	m_destinationRectangle.y = m_pos_y; // 400;
	m_destinationRectangle.w = m_sourceRectangle.w/4; //200;
	m_destinationRectangle.h = m_sourceRectangle.h/4;//300;

	//Free memory from Surface
	SDL_FreeSurface(m_Surface);
}

void GameObject::render()
{
	// Copy the texture in the rendering
	SDL_RenderCopyEx(m_Renderer, m_Texture, &m_sourceRectangle, &m_destinationRectangle,
		0, NULL, SDL_FLIP_NONE);

	//Draw in the rendering window
	SDL_RenderPresent(m_Renderer);
}
