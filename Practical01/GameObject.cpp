#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject()
{
	m_frames_num = 1;
	m_angle_num = 0;
	m_flip_char = 'N';
	m_speed_num = 1;
}

GameObject::~GameObject()
{

}

void GameObject::draw(int m_frames, const char* path, int m_pos_x, int m_pos_y, int m_angle, char m_flip, float m_scale, int m_speed)
{
	//Set the number of frames
	m_frames_num = m_frames;
	m_angle_num = m_angle;
	m_flip_char = m_flip;
	m_speed_num = m_speed;

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
	m_sourceRectangle.w = m_Surface->w/ m_frames; //500
	m_sourceRectangle.h = m_Surface->h; //690

	//Set the destination rectangle
	m_destinationRectangle.x = m_pos_x;// 100;
	m_destinationRectangle.y = m_pos_y; // 400;
	m_destinationRectangle.w = m_sourceRectangle.w * m_scale; //200;
	m_destinationRectangle.h = m_sourceRectangle.h * m_scale; //300;

	//Free memory from Surface
	SDL_FreeSurface(m_Surface);
}

void GameObject::render()
{
	// Copy the texture in the rendering
	if (m_flip_char == 'H')
	{
		SDL_RenderCopyEx(m_Renderer, m_Texture, &m_sourceRectangle, &m_destinationRectangle,
			m_angle_num, NULL, SDL_FLIP_HORIZONTAL);
	}
	else if (m_flip_char == 'V')
	{
		SDL_RenderCopyEx(m_Renderer, m_Texture, &m_sourceRectangle, &m_destinationRectangle,
			m_angle_num, NULL, SDL_FLIP_VERTICAL);
	}
	else
	{
		SDL_RenderCopyEx(m_Renderer, m_Texture, &m_sourceRectangle, &m_destinationRectangle,
			m_angle_num, NULL, SDL_FLIP_NONE);
	}

	//Draw in the rendering window
	SDL_RenderPresent(m_Renderer);
}

void GameObject::update()
{
	//I use 200 instead of 83, because it looks smoother, with 83 is still too fast
	m_sourceRectangle.x = m_sourceRectangle.w * ((SDL_GetTicks()* m_speed_num /200) % m_frames_num);
}
