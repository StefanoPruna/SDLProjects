#pragma once
#include "GameLoad.h"

//GameLoad is a subclass of GameObject
class GameObject : GameLoad
{
public:
	GameObject();
	~GameObject();
	void draw(int m_frames, const char* path, int m_pox_x, int m_pos_y, int m_angle, char m_flip, float m_scale, int m_speed);
	void render();
	void update();

private:
	SDL_Surface* m_Surface;
	SDL_Texture* m_Texture;

	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	int m_frames_num;
	int m_angle_num;
	char m_flip_char;
	int m_speed_num;
};

