#pragma once

#include "GameObject.h"
#include "Vector2D.h"

class Enemy : GameObject
{
public:
	Enemy(int m_pframes, const char* path, int m_pox_x, int m_pos_y);
	~Enemy();
	void draw();
	void update();
	void render();
	void enemyEvents();
	void enemyMove(Vector2D* m_EnemyVector);
	SDL_Rect getPosEnemy();

private:
	int m_frames;
	const char* m_texture;
	int m_position_x;
	int m_position_y;
	char flip;

	Vector2D* m_vector_left;
	Vector2D* m_vector_init;
};

