#pragma once
#include "GameObject.h"

class Obstacle : GameObject
{
public:
	Obstacle(int m_pframes, const char* path, int m_pox_x, int m_pos_y);
	~Obstacle();
	void draw();
	void update();
	void render();

private:
	int m_frames;
	const char* m_texture;
	int m_position_x;
	int m_position_y;
};

