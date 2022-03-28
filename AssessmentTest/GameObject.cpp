#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject()
{
	m_frames_num = 1;
}

GameObject::~GameObject()
{

}

void GameObject::draw(int m_frames, const char* path, int m_pos_x, int m_pos_y)
{
	//Set the number of frames
	m_frames_num = m_frames;

	//Create Surface from an image
	m_Surface = IMG_Load(path);

	if (m_Surface != nullptr)
		cout << "Load Surface - success\n";

	//Create Texture from Surface
	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);
	if (m_Texture != nullptr)
		cout << "Create texture from surface - success\n";

	//Set the source rectangle
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	m_sourceRectangle.w = m_Surface->w / m_frames;
	m_sourceRectangle.h = m_Surface->h;

	//Set the enemy source rectangle
	enemySourceRectangle.x = 0;
	enemySourceRectangle.y = 0;
	enemySourceRectangle.w = m_Surface->w / m_frames;
	enemySourceRectangle.h = m_Surface->h;

	//Set the destination rectangle
	m_destinationRectangle.x = m_pos_x;// 100;
	m_destinationRectangle.y = m_pos_y; // 400;
	m_destinationRectangle.w = m_sourceRectangle.w; //200;
	m_destinationRectangle.h = m_sourceRectangle.h; //300;

	//Set enemy destination rectangle
	enemyDestinationRectangle.x = m_pos_x;
	enemyDestinationRectangle.y = m_pos_y;
	enemyDestinationRectangle.w = enemySourceRectangle.w;
	enemyDestinationRectangle.h = enemySourceRectangle.h;

	//Free memory from Surface
	SDL_FreeSurface(m_Surface);
}

void GameObject::render(int mAngle, char mFlip)
{
	// Copy the texture in the rendering	
	if (mFlip == 'H')
		SDL_RenderCopyEx(m_Renderer, m_Texture, &m_sourceRectangle, &m_destinationRectangle,
			mAngle, NULL, SDL_FLIP_HORIZONTAL);
	else	
		SDL_RenderCopyEx(m_Renderer, m_Texture, &m_sourceRectangle, &m_destinationRectangle,
			mAngle, NULL, SDL_FLIP_NONE);
	
	/*if (mFlip == 'H')
		SDL_RenderCopyEx(m_Renderer, m_Texture, &enemySourceRectangle, &enemyDestinationRectangle,
			mAngle, NULL, SDL_FLIP_HORIZONTAL);
	else
		SDL_RenderCopyEx(m_Renderer, m_Texture, &enemySourceRectangle, &enemyDestinationRectangle,
			mAngle, NULL, SDL_FLIP_NONE);*/

	//Draw in the rendering window
	SDL_RenderPresent(m_Renderer);
}

void GameObject::update()
{
	//I use 200 instead of 83, because it looks smoother, with 83 is still too fast
	m_sourceRectangle.x = m_sourceRectangle.w * ((SDL_GetTicks() /200) % m_frames_num);

	enemySourceRectangle.x = enemySourceRectangle.w * ((SDL_GetTicks() / 200) % m_frames_num);
}
